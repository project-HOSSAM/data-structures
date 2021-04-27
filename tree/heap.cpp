#include <cmath>
#include <vector>
#include <iostream>

class MaxHeap {
private:
    std::vector<int> heap;
private:
    int left(int);
    int right(int);
    int parent(int);
    void heapifyUp(int);
    void heapifyDown(int);

public:
    void insert(int);
    void deleteMax();
    int findMax();
    void print();
};  

int MaxHeap::left(int i) { return i * 2 + 1 ;};
int MaxHeap::right(int i) {return i * 2 + 2 ;};
int MaxHeap::parent(int i) {return std::floor(i/2) ;};

void MaxHeap::heapifyUp(int i) {
    if(i <= 0) return;
    if(this->heap[i] > this->heap[this->parent(i)]) {
        std::swap(this->heap[i], this->heap[this->parent(i)]);
        this->heapifyUp(this->parent(i));
    }
}

void MaxHeap::heapifyDown(int i) {
    if(this->left(i) > this->heap.size() - 1) return;
    // node smaller than it children
    if(this->heap[i] < this->heap[this->left(i)] || this->heap[i] < this->heap[this->right(i)]) {
        // the left child is bigger
        if(this->heap[this->left(i)] > this->heap[this->right(i)]) {
            std::swap(this->heap[i], this->heap[this->left(i)]);
            this->heapifyDown(this->left(i));
        } else {
            // the right child is bigger
            std::swap(this->heap[i], this->heap[this->right(i)]);
            this->heapifyDown(this->right(i));
        }
    }
}


void MaxHeap::insert(int i) {
    // 1) insert at the last element
    this->heap.push_back(i);
    // 2) position the element to the right place
    this->heapifyUp(this->heap.size() - 1);
}

void MaxHeap::deleteMax() {
    // 1) remove the root and replace it by the last element
    std::swap(this->heap[0], this->heap[this->heap.size() -1]);
    this->heap.pop_back();
    this->heapifyDown(0);
}

int MaxHeap::findMax() {
    return this->heap[0];
}

void MaxHeap::print() {
    for(auto i : this->heap) {
        std::cout<< i << " ";
    }
    std::cout << '\n';
}
