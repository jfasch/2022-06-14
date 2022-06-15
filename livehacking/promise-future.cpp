#include <chrono>
#include <thread>
#include <future>
#include <iostream>


using namespace std::chrono_literals;

static constexpr auto TEN_MILLION_YEARS = 2s;

int main()
{
    std::promise<int> answer_promise;
    auto answer_future = answer_promise.get_future();

    std::thread chew_answer([&answer_promise]() {
        std::this_thread::sleep_for(TEN_MILLION_YEARS);
        answer_promise.set_value(42);
    });

    std::cout << answer_future.get() << std::endl;

    chew_answer.join();
    return 0;
}

