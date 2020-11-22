//https://contest.yandex.ru/contest/19592/run-report/34390679/
#include <iostream>

void getarray(int* arr, int n) {
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
}

int binsearch(int *arr, int n) {
  int left = 0;
  int right = n - 1;
  while (right != left) {
    int middle = (right + left) / 2;
    int prev = middle - 1;
    int next = middle + 1;
    if (right - left == 1) {
      if (arr[right] > arr[left])
        return right;
      else return left;
    } else if (arr[prev] < arr[middle] && arr[middle] < arr[next]) {
      left = middle;
    } else if (arr[prev] > arr[middle] && arr[middle] > arr[next]) {
      right = middle;
    } else if (arr[prev] < arr[middle] && arr[middle] > arr[next]) {
      return middle;
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  getarray(arr, n);
  
  int pos = binsearch(arr, n);
  std::cout << pos << std::endl;
  delete[] arr;
  return 0;
}
