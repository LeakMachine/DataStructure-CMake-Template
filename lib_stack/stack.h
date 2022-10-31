#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_


#include <iostream>

class Stack {
private:
    int* data;
    int top1;
    int size;

public:
    bool isFull() { if (top1 == size - 1) { return true; } else { return false; } };
    bool isEmpty() { if (top1 == -1) { return true; } else { return false; } };
    Stack(int _size) {
        if (_size < 1) {
            throw std::logic_error("Size can't be lower than 1");
        }
        size = _size;
        top1 = -1;
        data = new int[size];
    }
    ~Stack() {
        delete[] data;
        top1 = -1;
        size = 0;
    }
    void push(const int& val) {
        if (!isFull()) {
            top1++;
            data[top1] = val;
        }
        else {
            throw std::logic_error("ERROR in PUSH: Stack is full!");
        }
    }
    int pop() {
        int val;
        if (!isEmpty()) {
            val = data[top1];
            top1--;
        }
        else {
            throw std::logic_error("ERROR in POP: Stack is empty!");
        }

        return val;
    }
    int top() {
        if (isEmpty()) {
            throw std::logic_error("ERROR in TOP: Stack is Empty!");
        }
        return data[top1];
    }
};

#endif