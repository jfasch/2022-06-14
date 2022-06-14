#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <memory>
#include <variant>

using namespace std::chrono_literals;

class TodoList final
{
public:
    using todo_item = std::variant<std::function<void()>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string, todo_item>;

public:
    TodoList(std::initializer_list<std::pair<const std::string, todo_item>> items)
    : _tdl{items} {}

    TodoList() = default;
    TodoList(const TodoList&) = delete;
    TodoList& operator=(const TodoList&) = delete;

    void add_item(const std::string& name, std::function<void()> func)
    {
        _tdl[name] = func;
    }

    void start()
    {
        for (auto& [name, item]: _tdl) {
            std::cout << "Starting NAME: " << name << std::endl;
            item = std::shared_ptr<std::thread>(new std::thread(std::get<0>(item)));
        }
    }
    
    void wait()
    {
        for (auto& [name, item]: _tdl) {
            std::cout << "Waiting for NAME: " << name << std::endl;
            std::get<1>(item)->join();
        }
    }

private:
    todo_list _tdl;
};

int main()
{
    TodoList tdl{
        {
            "up 1 to 10",
            [lower=1, upper=10](){
                for (int i=lower; i<=upper; i++) {
                    std::cout << "UP: " << i << std::endl;
                    std::this_thread::sleep_for(1s);
                }
            }
        },
        {
            "down 1000 to 980",
            [upper=1000, lower=980](){
                for (int i=upper; i>=lower; i--) {
                    std::cout << "DOWN: " << i << std::endl;
                    std::this_thread::sleep_for(500ms);
                }
            }
        },
    };

    tdl.start();
    tdl.wait();

    return 0;
}
