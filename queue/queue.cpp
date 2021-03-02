#include <iostream>
#include <vector>

template<typename T>
class Queue {
private:
    std::vector<T> queue;

public:
    void enqueue(T value) {
        this->queue.emplace(queue.begin(), value);
    };

    void dequeue() {
        this->queue.pop_back();
    };

    T peek() {
        return this->queue.back();
    };
    
    void log() {
        for(T i : this->queue) {
            std::cout << " | " << i << " | ";
        };
        std::cout << std::endl;
    };
};