//https://contest.yandex.ru/contest/19592/run-report/34390679/
#include <iostream>

int *getarray(int n) {
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  return arr;
}

int binsearch(int *arr, int n) {
  int left = 0;
  int right = n - 1;
  while (right != left) {
    int middle = (right + left) / 2;
    //std::cout << "середина нач " << middle << " ";
    //std::cout << "левый начало" << left << " ";
    //std::cout << "правый начало" << right << std::endl;
    int prev = middle - 1;
    int next = middle + 1;
    if (right - left == 1) {
      if (arr[right] > arr[left])
        return right;
      else return left;
    } else if (arr[prev] < arr[middle] && arr[middle] < arr[next]) {
      left = middle;
      //std::cout << "левый бок" << left << std::endl;
    } else if (arr[prev] > arr[middle] && arr[middle] > arr[next]) {
      right = middle;
      //std::cout << "правый бок" << right << std::endl;
    } else if (arr[prev] < arr[middle] && arr[middle] > arr[next]) {
      //std::cout << "середина - ответ" << middle << std::endl;
      return middle;
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  int *arr = getarray(n);
  int pos = binsearch(arr, n);
  std::cout << pos << std::endl;
  delete[] arr;
  return 0;
}