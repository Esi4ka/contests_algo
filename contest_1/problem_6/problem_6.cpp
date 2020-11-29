//https://contest.yandex.ru/contest/19592/run-report/34606513/
#include <iostream>

class Heap {
 public:
  Heap();
  ~Heap();
  void add(int key);
  void SpAdd(int key);
  int extractTop();
  int SpExtractTop();
  int getTop();
  bool isEmpty();
 private:
  int *buffer;
  int capacity;
  int size;
  void siftUp(int index);
  void siftDown(int index);
};

Heap::Heap() : capacity(1), size(0) {
  buffer = new int[capacity];
}

Heap::~Heap() {
  delete[] buffer;
}

int Heap::getTop() {
  return buffer[0];
}

bool Heap::isEmpty() {
  return size == 0;
}

void Heap::add(int key) {
  if (size == capacity) {
    capacity *= 2;
    int *new_buffer = new int[capacity];
    for (int i = 0; i < size; ++i)
      new_buffer[i] = buffer[i];
    delete[] buffer;
    buffer = new_buffer;
  }
  buffer[size] = key;
  ++size;
  siftUp(size - 1);
}

void Heap::SpAdd(int key) {
  if (size == capacity) {
    capacity *= 2;
    int *new_buffer = new int[capacity];
    for (int i = 0; i < size; ++i)
      new_buffer[i] = buffer[i];
    delete[] buffer;
    buffer = new_buffer;
  }
  buffer[size] = key;
  ++size;
}

int Heap::extractTop() {
  int result = buffer[0];
  buffer[0] = buffer[size - 1];
  --size;

  if (size * 2 == capacity) {
    int *new_buffer = new int[size];
    for (int i = 0; i < size; ++i)
      new_buffer[i] = buffer[i];

    capacity = size;
    delete[] buffer;
    buffer = new_buffer;
  }
  siftDown(0);
  return result;
}

int Heap::SpExtractTop() {
  int result = buffer[0];
  buffer[0] = buffer[size - 1];
  --size;
  if (size * 2 == capacity) {
    int *tmp_buffer = new int[size];
    for (int i = 0; i < size; ++i)
      tmp_buffer[i] = buffer[i];

    capacity = size;
    delete[] buffer;
    buffer = tmp_buffer;
  }
  return result;
}

void Heap::siftUp(int index) {
  while (index != 0 && buffer[index] > buffer[(index - 1) / 2]) {
    int tmp_value = buffer[index];
    buffer[index] = buffer[(index - 1) / 2];
    buffer[(index - 1) / 2] = tmp_value;
    index = (index - 1) / 2;
  }
}

void Heap::siftDown(int index) {
  while (index < size) {
    int largest = index;
    if (index * 2 + 1 < size && buffer[index * 2 + 1] > buffer[largest])
      largest = index * 2 + 1;
    if (index * 2 + 2 < size && buffer[index * 2 + 2] > buffer[largest])
      largest = index * 2 + 2;

    if (largest != index)
      std::swap(buffer[index], buffer[largest]);
    else
      return;

    index = largest;
  }
}

int main() {
  int count = 0;
  int max_weight = 0;
  int tmp_weight = 0;
  int steps = 0;

  Heap heap;
  Heap tmp;

  std::cin >> count;

  for (int i = 0; i < count; ++i) {
    std::cin >> tmp_weight;
    heap.add(tmp_weight);
  }
  std::cin >> max_weight;

  while (!heap.isEmpty()) {
    tmp_weight = 0;

    while (!heap.isEmpty() && tmp_weight + heap.getTop() <= max_weight) {
      tmp_weight += heap.getTop();
      tmp.SpAdd(heap.extractTop() / 2);
    }

    while (!tmp.isEmpty()) {
      int tmp_weight = tmp.SpExtractTop();
      if (tmp_weight != 0)
        heap.add(tmp_weight);
    }
    steps++;
  }

  std::cout << steps;
  return 0;
}