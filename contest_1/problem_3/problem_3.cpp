#include <iostream>

int Find(const int *arr, int n) {
 int inc = 1;
 while (inc < n) {
 if(arr[inc-1] < arr[inc]) {
 std::cout « inc « " ";
 inc *=2;
 std::cout « inc « " ";
 break;
 }
 return inc;
 }
}

void getarray(int* arr, int n) {
 for (size_t i = 0; i < n; ++i) {
 std::cin » arr[i];
 }
}

int binsearch(int* arr, int n) {
 int left = 0;
 int right = n;
 int m = 0;
 

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

 std::cout « m;
}

int main() {
 int n;
 std::cin » n;
 int* arr = new int[n];
 getarray(arr, n);

 if(n == 2) {
 if(arr[0] > arr[1]) {
 std::cout « 0;
 return 0;
 }
 else {
 std::cout « 1;
 return 0;
 }
 }
 int line = Find(arr, n);
 std::cout « binsearch(arr, line) « std::endl;
 delete[] arr;
 return 0;
}
