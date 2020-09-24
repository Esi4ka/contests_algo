//https://contest.yandex.ru/contest/19592/run-report/34076679/
#include <iostream>

int main() {
  int input;
  std::cin >> input;
  int k = 0;
  for (int i = 2; i <= input; i++) {
    if (input % i == 0) {
      while (input % i == 0) {
        k++;
        std::cout << i << " ";
        input = input / i;
      }
    }
  }
}

