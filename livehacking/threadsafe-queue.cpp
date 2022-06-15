#include <chrono>
#include <thread>
#include <deque>
#include <iostream>
#include <vector>
#include <pthread.h>


using namespace std::chrono_literals;

class ThreadSafeQueue
{
public:
    ThreadSafeQueue(size_t maxelem) 
    : _maxelem(maxelem)
    {
        pthread_mutex_init(&_lock, nullptr);
        pthread_cond_init(&_not_empty, nullptr);
        pthread_cond_init(&_not_full, nullptr);
    }
    void push(int i)
    {
        pthread_mutex_lock(&_lock);
        {
            while (_queue.size() == _maxelem)
                pthread_cond_wait(&_not_full, &_lock);
            _queue.push_back(i);
        }
        pthread_mutex_unlock(&_lock);

        pthread_cond_signal(&_not_empty);
    }
    int pop()
    {
        int i;
        pthread_mutex_lock(&_lock);
        {
            while (_queue.size() == 0)
                pthread_cond_wait(&_not_empty, &_lock);
            i = _queue.front();
            _queue.pop_front();
        }
        pthread_mutex_unlock(&_lock);

        pthread_cond_signal(&_not_full);
        return i;
    }

private:
    size_t _maxelem;
    std::deque<int> _queue;
    pthread_mutex_t _lock;
    pthread_cond_t _not_empty;
    pthread_cond_t _not_full;
};


int main()
{
    ThreadSafeQueue queue(10);

    std::vector<std::thread> consumers;
    for (int i=0; i<10; i++)
        consumers.push_back(
            std::thread([&queue](){
                while (true)
                    std::cout << queue.pop() << std::endl;
            })
        );

    std::vector<std::thread> producers;
    for (int i=0; i<10; i++) 
        producers.push_back(
            std::thread([&queue](){
                int i = 0;
                while (true) {
                    queue.push(i++);
                    std::this_thread::sleep_for(0.5s);
                }
            })
        );

    for (auto& consumer: consumers)
        consumer.join();
    for (auto& producer: producers)
        producer.join();

    return 0;
}
