//https://contest.yandex.ru/contest/19592/run-report/34593667/
#include <iostream>
#include <assert.h>

class Stack {
 public:
  Stack();

  ~Stack();

  void Push(int a); //обычный пуш
  int Pop();  // не извлекает эллемент из стека
  int Top();  // извлекает
  bool IsEmpty() const { return top == -1; }

 private:
  int *buffer;
  int bufferSize;
  int top;

  void grow(); //увеличение размерности массива при заполнении
};

int getPriority(char operand) { // получение приоритета операнда
  if (operand == '*' || operand == '/') {
    return 4;
  }
  if (operand == '+' || operand == '-') {
    return 3;
  }
  if (operand == '(') {
    return 2;
  }
  if (operand == ')') {
    return 1;
  }
  return -1;
}

Stack::Stack() : bufferSize(2), top(-1) {
  buffer = new int[bufferSize];
}

Stack::~Stack() {
  delete[] buffer;
}

void Stack::Push(int a) {
  if (top + 2 > bufferSize) {
    grow();
  }
  //assert(top + 1 <  bufferSize);
  buffer[++top] = a;
}

int Stack::Pop() {
  assert(top != -1);
  return buffer[top];
}

int Stack::Top() {
  assert(top != -1);
  return buffer[top--];
}

void Stack::grow() {
  int newBufferSize = bufferSize * 2;
  int *tempBuffer = new int[newBufferSize];
  for (int i = 0; i < bufferSize; ++i) {
    tempBuffer[i] = buffer[i];
  }
  delete[] buffer;
  buffer = tempBuffer;
  bufferSize = newBufferSize;
}

int calculate(std::string outStr) {
  Stack stack;
  bool isNumberFirst = true;
  int tempInt = 0;
  int first = 0;
  int second = 0;
  for (int i = 0; i < outStr.length(); ++i) {
    if (isdigit(outStr[i])) {
      if (isNumberFirst) {
        stack.Push(outStr[i] % 48); // из-за таблицы
        isNumberFirst = false;
      } else {
        tempInt = stack.Top();
        stack.Push(tempInt * 10 + outStr[i] % 48);
      }
    }
    if (outStr[i] == ' ') { //по пробелу определяем что число закончилось
      isNumberFirst = true;
    }
    if (outStr[i] == '+') {

      first = stack.Top();
      second = stack.Top();
      stack.Push(first + second);
    }
    if (outStr[i] == '-') {
      first = stack.Top();
      second = stack.Top();
      stack.Push(second - first);
    }
    if (outStr[i] == '/') {
      first = stack.Top();
      second = stack.Top();
      stack.Push(second / first);
    }
    if (outStr[i] == '*') {
      first = stack.Top();
      second = stack.Top();
      stack.Push(first * second);
    }
  }
  return stack.Top();
}

int main() {
  char symbol = '0'; //текущий элемент
  std::string outStr;      // выходная строка в постфиксной нотации
  bool isPreviousSymbolNumber = false; // является ли пред символ числом
  Stack stackForCalculate; // стек для перевода
  while (scanf("%c", &symbol) == 1) {
    if (symbol == '\n' || symbol == '\0') {
      break;
    }
    if (isdigit(symbol) != 0) {
      isPreviousSymbolNumber = true; //ставим флаги
      outStr.push_back(symbol); //заносим в выходную строку все числа
    } else {
      //if ( symbol == '(' || '+' || '-' || '*' || '/' || ')' )
      if (isPreviousSymbolNumber) {
        outStr.push_back(' '); //заносим пробелы после чисел
        isPreviousSymbolNumber = false; // меняем флаги
      }
      if (symbol == '(' || symbol == ')') {
        if (symbol == '(') {
          stackForCalculate.Push(symbol); // ( всегда в стек
        } else {
          while (stackForCalculate.Pop() != '(') {
            outStr.push_back(char(stackForCalculate.Top())); //извлекаем пока не найдем (
          }
          stackForCalculate.Top();
        }
      } else {
        if (stackForCalculate.IsEmpty()) {
          stackForCalculate.Push(symbol); //если пуст просто кладем операнд
        } else {

          while (!stackForCalculate.IsEmpty()) { // иначе
            if (getPriority(char(stackForCalculate.Pop())) >= getPriority(symbol)) {
              outStr.push_back(char(stackForCalculate.Top())); // если операнд ниже или равен приоритетом
            } else {
              break; //если выше
            }
          }
          stackForCalculate.Push(symbol); //все равно кладем в стек
        }
      }
    }
  }
  while (!stackForCalculate.IsEmpty()) {
    outStr.push_back(char(stackForCalculate.Top())); //заносим оставшиеся операторы в строку
  }
  std::cout << calculate(outStr); //считаем результат

  return 0;
}