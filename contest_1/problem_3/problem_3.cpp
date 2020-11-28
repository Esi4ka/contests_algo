#include <iostream>


int binsearch(const int *array, int left, int right) {
  while (true) {
    int mid = left + (right - left) / 2;

    if (array[mid] > array[mid + 1] && array[mid] > array[mid - 1])
      return mid;

    if (array[mid] > array[mid + 1])
      right = mid;
    else
      left = mid + 1;
  }
}


int find(const int *arr, int left, int right) {
  int tmp = 1;
  int prev = 0;
  while (tmp < right) {
    if(arr[tmp-1] < arr[tmp]) {
      prev = tmp;
      tmp*=2;
    }
  }

  if(tmp > right + 1) {
    tmp = right;
  }

  return(binsearch(arr, prev, tmp));
}





int main() {
  int n;
  std::cin >> n;
  int * arr = new int[n];
  for (size_t i = 0; i < n; ++i)
    std::cin >> arr[i];

  std::cout << find(arr, 0, n - 1) << std::endl;

  delete [] arr;
  return 0;
}
