#include <cmath>
#include <iostream>
#include <vector>

class MaxHeap {
private:
  std::vector<int> heap;

public:
  void insert(int);
  void print();
  bool isEmpty();
  int maxValue();
};

void MaxHeap::insert(int item) {
  this->heap.emplace_back(item);
  auto newItemIndex = this->heap.size() - 1;
  while (true) {
    auto parent = std::floor(newItemIndex / 2);
    if (this->heap[parent] > this->heap[newItemIndex]) {
      return;
    } else if (newItemIndex == 0)
      return;
    std::swap(this->heap[parent], this->heap[newItemIndex]);
    newItemIndex = parent;
  }
};

bool MaxHeap::isEmpty() {
    if(this->heap.size() >= 1) return true;
    return false;
};

int MaxHeap::maxValue() {
    return this->heap[0];
}

