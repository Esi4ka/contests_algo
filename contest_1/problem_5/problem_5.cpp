#include <iostream>


class Stack{
 private:
    int size;
    int capacity;
    int* buffer;
    void grow();
 public:
    Stack();
    ~Stack();
    bool isEmpty();
    void Push (int val);
    int Pop();
    int peek();
};

Stack::Stack(){
    size = 0;
    capacity = 8;
    buffer = new int[capacity];
}
Stack::~Stack(){
    delete[] buffer;
}

bool Stack::isEmpty(){
    return !size;
}

void Stack::grow(){
    int* temp = new int[capacity * 2];
    for(int i = 0; i < capacity; ++i){
        temp[i] = buffer[i];
    }
    delete[] buffer;
    buffer = temp;
    capacity *= 2;
}
void Stack::Push(int val){
    if(size + 1 == capacity){
        grow();
    }
    buffer[size] = val;
    size++;
}

int Stack::Pop() {
    if(isEmpty()){
        return -1;
    }
    int res = buffer[--size];
    return res;
}

int Stack::peek() {
    if(isEmpty()){
        return -1;
    }
    return buffer[size - 1];
}



int getPriority (int action){
    switch (action){
        case -1 : return 1;
        case -2 : return 1;
        case -3 : return 2;
        case -4 : return 2;
    }
    return 0;
}

int charToInt (char c){
    switch (c){
            case '+' :
                return -1;
            case '-' :
                return -2;
            case '*' :
                return -3;
            case '/' :
                return -4;
            case '(' :
                return -5;
            case ')' :
                return -6;
            default :
                return c - (int)'0';
        }
}

int postfixCount(int* postfix, int postfixCapacity){
    Stack* numbers = new Stack();
    int current = 0;
    for(int i = 0; i < postfixCapacity; ++i){
        current = postfix[i];
        if(current >= 0){
           
            numbers->Push(current);
        }
        else{
            int num1 = numbers->Pop();
            int num2 = numbers->Pop();
            int res = 0;
            switch(current){
                case -1 :
                    res = num1 + num2;
                    break;
                case -2 :
                    res = num2 - num1;
                    break;
                case -3 :
                    res = num1 * num2;
                    break;
                case -4 :
                    res = num2 / num1;
                    break;
            }
            numbers->Push(res);
        }
    }
    int res =  numbers->Pop();
    delete numbers;
    return res;
}

int InfToPost(const std::string& str) {
    Stack* actions = new Stack();
    int length = str.size();
    int* postfix = new int[length];
    int pos = 0;
    int pCapacity = 0;
    int curr = 0;
    while(pos < length){
        curr = charToInt(str[pos]);
        if(curr >= 0){
            int i = 1;
            while(pos + i < length && isdigit(str[pos + i])){
                curr = curr * 10 + charToInt(str[pos + i]);
                i++;
            }
            pos += i - 1;
        }
        if(curr >= 0){
            postfix[pCapacity++] = curr;
        } else if(curr == -5){
            actions->Push(curr);
        } else if(curr == -6){
            int upAction = actions->Pop();
            while(upAction != -5){
                postfix[pCapacity++] = upAction;
                upAction = actions->Pop();
            }
        } else {
            while(!actions->isEmpty()){
                    if(getPriority(actions->peek()) < getPriority(curr)){
                        break;
                    }
                    postfix[pCapacity++] = actions->Pop();
            }
            actions->Push(curr);
        }
        pos++;
    }
    while(!actions->isEmpty()){
            postfix[pCapacity++] = actions->Pop();
        }

    delete actions;
    return postfixCount(postfix, pCapacity);
}


int main(){
    std::string input;
    std::cin >> input;
    std::cout << InfToPost(input);
    return 0;
}
