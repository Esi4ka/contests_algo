//https://contest.yandex.ru/contest/19592/run-report/34606074/
#include <iostream>
#define INITAL_CAPACITY 4

class Stack {
 public:
  Stack();
  ~Stack();
  void Push(int x);
  int Pop();
  bool IsEmpty();
 private:
  int *buffer;
  int size;
  int capacity;
  void grow();
};

Stack::Stack() : size(0), capacity(INITAL_CAPACITY) {
  buffer = new int[INITAL_CAPACITY];
}

bool Stack::IsEmpty() {
  return size == 0;
}

int Stack::Pop() {
  if (size > 0) {
    int value = buffer[size - 1];
    size--;
    return value;
  } else {
    return -1;
  }
}

void Stack::grow() {
  capacity *= 2;
  int *new_buffer = new int[capacity];
  for (int i = 0; i < size; ++i)
    new_buffer[i] = buffer[i];
  delete[] buffer;
  buffer = new_buffer;
}

void Stack::Push(int x) {
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
  void shift();
  int pop_front();
 private:
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

bool Solving(int n, int *input) {
  bool is_true = 1;
  int Temp1 = 0, Temp2 = 0;
  Queue Solving;

  for (int i = 0; i < n; i++) {
    if (input[2 * i] == 2) {
      int a = Solving.pop_front();
      if (a != input[2 * i + 1]) {
        is_true = 0;
      }
    } else {
      Solving.push_back(input[2 * i + 1]);
    }
  }
  return is_true;
}

int main() {
  int n;
  std::cin >> n;
  int *input = new int[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    std::cin >> input[i];
  }
  int is_right = 0;
  is_right = Solving(n, input);
  if (is_right == 0)
    std::cout << "NO";
  else
    std::cout << "YES";
  delete[] input;
  return 0;
}