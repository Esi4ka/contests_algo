#include <iostream>
#include <cstring>

class Stack {
 public:
  Stack();
  ~Stack();
  void Push(int x);
  int Pop();
  bool IsEmpty()const;
 private:
  int *buffer;
  static const int INITAL_CAPACITY = 4;
  static const int GROW_SIZE = 2;
  int size;
  int capacity;
  void grow();
  void shift();
};

Stack::Stack() : size(0), capacity(INITAL_CAPACITY) {
  buffer = new int[INITAL_CAPACITY];
}

bool Stack::IsEmpty() const {
  return size == 0;
}

int Stack::Pop() {
  if(size < 1/3 * capacity)
    shift();
  if (size > 0) {
    int value = buffer[size - 1];
    size--;
    return value;
  } else {
    return -1;
  }
}

void Stack::grow() {
  capacity *= GROW_SIZE;
  int *new_buffer = new int[capacity];
  memcpy (new_buffer, buffer, sizeof(buffer));
  delete[] buffer;
  buffer = new_buffer;
}

void Stack::shift() {
  capacity /= GROW_SIZE;
  int *new_buffer = new int[capacity];
  memcpy (new_buffer, buffer, sizeof(buffer));
  delete[] buffer;
  buffer = new_buffer;
}


void Stack::Push(const int x) {
  if (size == capacity)
    grow();
  buffer[size] = x;
  size++;
}

Stack::~Stack() {
  delete[] buffer;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
class Queue {
 public:
  void push_back(int x);
  int pop_front();
 private:
  void shift();
  Stack out;
  Stack in;
};

void Queue::push_back(int x) {
  in.Push(x);
}

void Queue::shift() {
  if (out.IsEmpty()) {
    while (!in.IsEmpty())
      out.Push(in.Pop());
  }
}

int Queue::pop_front() {
  shift();
  int temp = out.Pop();
  return temp;
}

bool Solving(const int n, const int *input) {
  bool is_good_input = true;
  Queue Solving;
  for (int i = 0; i < n; i++) {
    if (input[2 * i] == 2) {
      int a = Solving.pop_front();
      if (a != input[2 * i + 1]) {
        is_good_input = false;
      }
    } else {
      Solving.push_back(input[2 * i + 1]);
    }
  }
  return is_good_input;
}

int main() {
  int n;
  std::cin >> n;
  int *input = new int[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    std::cin >> input[i];
  }
  if (Solving(n, input) == 0)
    std::cout << "NO";
  else
    std::cout << "YES";
  delete[] input;
  return 0;
}
//https://contest.yandex.ru/contest/19592/run-report/34606074/
//старая посылка
//https://contest.yandex.ru/contest/19592/run-report/35026137/
//новая посылка исправленного кода
