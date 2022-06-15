#include <functional>
#include <iostream>


// class print_function
// {
// public:
//     print_function(const std::string& message) : _message(message) {}
//     void operator()() const
//     {
//         std::cout << _message << std::endl;
//     }
// private:
//     const std::string& _message;
// };

std::function<void()> create_print_function(std::string message)
{
    // return print_function(message);
    auto print_function = [&message]() {
        std::cout << message << std::endl;
    };
    return print_function;
}

int main()
{
    auto p = create_print_function("hallo joerg");
    p();

    return 0;
}
