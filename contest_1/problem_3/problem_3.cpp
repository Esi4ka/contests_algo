//https://contest.yandex.ru/contest/19592/run-report/34390679/
#include <iostream>

void getarray(int* arr, int n) {
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
}

int binsearch(int* arr, int n) {
  int left = 0;
  int right = n;
  int m = 0;
  
  if(n == 2) {
      if(arr[0] > arr[1]) {
          std::cout << 0;
      }
      else {
          std::cout << 1;
      }
  }
  else if (arr[0] > arr[1]) {
      std::cout << 0;
  }
  else if(arr[n-1] > arr[n-2]) {
      std::cout << n-1;
  }

  else {
    while(true) {
      m = (left+right)/2;
      if(arr[m] > arr[m-1] && arr[m] > arr[m+1])
          break;
      if(arr[m] > arr[m-1]) {
          left = m;
          continue;
      }
      right = m;
    }
    std::cout << m;
  }
}

int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  getarray(arr, n);
  std::cout << binsearch(arr, n) << std::endl;
  delete[] arr;
  return 0;
}
