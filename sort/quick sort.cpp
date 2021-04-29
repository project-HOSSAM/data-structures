#include <iostream>
#include <vector>

int partition(std::vector<int> &v, int start, int end) {

  int pivot = end;
  int j = start;
  for (int i = start; i < end; ++i) {
    if (v[i] < v[pivot]) {
      std::swap(v[i], v[j]);
      j++;
    }
  }
  std::swap(v[j], v[pivot]);
  return j;
}

void quicksort(std::vector<int> &v, int start, int end) {
  if (start < end) {
    int p = partition(v, start, end);
    quicksort(v, start, p - 1);
    quicksort(v, p + 1, end);
  }
}

int main() {
  std::vector<int> a = {2, 5, 7, 14, 6, 8, 1};
  quicksort(a, 0, 6);
  for (int i = 0; i < 7; i++) {
    std::cout << a[i] << "\n";
  }
}
