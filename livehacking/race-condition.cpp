#include <thread>
#include <string>
#include <iostream>
#include <mutex>

int main()
{
    unsigned long the_integer = 0;
    std::mutex lock;

    auto func = [&the_integer, &lock](){
        for (unsigned long i=0; i<100*1000*1000; i++) {
            std::scoped_lock guard(lock);
            ++the_integer;
        }
    };

    std::thread t1(func);
    std::thread t2(func);
    t2.join();
    t1.join();

    std::cout << the_integer << std::endl;

    return 0;
}
