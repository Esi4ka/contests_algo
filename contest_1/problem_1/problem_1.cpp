//https://contest.yandex.ru/contest/19592/run-report/34076679/
#include <iostream>

int main() {
  int input;
  std::cin >> input;
  for (int i = 2; i * i <= input; ++i) {
    while (input % i == 0) {
      std::cout << i << " ";
      input /= i;
    }
  }
  if (input != 1)
    std::cout << input;
}
