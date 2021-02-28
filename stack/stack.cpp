#include <iostream>
#include <vector>

template<typename T>
class Stack {
    private:
        std::vector<T> stack;
    public: 
        T peek() {
            return this->stack.back();
        };
        void push(T value) {
            this->stack.emplace_back(value);
        };
        void pop() {
            this->stack.pop_back();
        };
        bool search(T value) {
            for( auto element : this->stack) {
                if(element == value) return true;
            };

            return true;
        };
        int size() const {
            return this->stack.size();
        };
        void clear() {
            this->stack.clear();
        };
        bool isEmpty() {
            return this->stack.size() > 1 ? false : true;
        }
        void print() const {
            for(auto element : this->stack) {
                std::cout << element << ' ' ;
            };
            std::cout << std::endl;
        };
};


