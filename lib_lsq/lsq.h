// Copyright 2022 Vinokurov Ivan

#ifndef LIB_LSQ_LSQ_H_
#define LIB_LSQ_LSQ_H_

#include "../lib_list/list.h"
#include <iostream>

template <class Type> class Stack;
template <class Type> class Queue;

template <class Type>
class Stack {
private:
    CList list;
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
    }
    ~Stack() {
        top1 = -1;
        size = 0;
    }
    void push(const Type& val) {
        if (!isFull()) {
            top1++;
            list.push_back(val);
        }
        else {
            throw std::logic_error("ERROR in PUSH: Stack is full!");
        }
    }
    int pop() {
        int val;
        if (!isEmpty()) {
            val = list.pop_back();
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
        CList temp;
        temp = list;
        int val = temp.pop_back();
        return val;
    }
};

template <class Type>
class Queue {
private:
    CList list;
    int top1;
    int size;
    int end;

public:
    bool isFull() { if (end == size - 1) { return true; } else { return false; } };
    bool isEmpty() { if (end - top1 < 0) { return true; } else { return false; } };
    Queue(int _size) {
        if (_size < 1) {
            throw std::logic_error("Size can't be lower than 1");
        }
        size = _size;
        top1 = 0;
        end = -1;
    }
    ~Queue() {
        top1 = 0;
        end = -1;
        size = 0;
    }
    void push(const Type& val) {
        if (!isFull()) {
            end++;
            list.push_front(val);
        }
        else {
            if (isFull() && top1 != 0) {
                end = size - top1;
                list.push_front(val);
                top1 = 0;
            }
            else {
                throw std::logic_error("ERROR in PUSH: Queue is full!");
            }
        }
    }
    int pop() {

        int val;
        if (!isEmpty()) {
            val = list.pop_back();
            top1++;
        }
        else {
            throw std::logic_error("ERROR in POP: Queue is empty!");
        }

        return val;
    }
    int top() {
        if (isEmpty()) {
            throw std::logic_error("ERROR in TOP: Queue is Empty!");
        }
        CList temp;
        temp = list;
        int val = temp.pop_back();
        return val;
    }
};

#endif