//https://contest.yandex.ru/contest/19592/run-report/34103217/
#include <iostream>

int win(int n, int k) {
  if (n <= 2) {
    return k % n;
  }
  return (k + win(n - 1, k)) % n;
}

int main() {
  int n;
  int k;
  std::cin >> n >> k;
  int t = win(n, k);
  std::cout << 1 + t;
}
