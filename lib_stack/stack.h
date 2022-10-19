#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_


#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class Stack {
private:
  T* data;
  size_t top;
  size_t size;
  bool isFull = []() {if (top == size - 1) { return true } else { return false } };
  bool isEmpty = []() {if (top == -1) { return true } else { return false } };
public:
  explicit Stack(size_t _size = 1) : size(_size) {
    if (sz == 0)
      throw std::out_of_range("Stack size should be greater than zero");
    data = new T[size]();
  }
  Stack(T* _data, size_t s) : size(s) {
      assert(_data != nullptr && "Stack ctor requires non-nullptr arg");
      data = new T[size];
      std::copy(_data, _data + size, data);
  }
  ~Stack() {
    delete[] data;
    top = -1;
    size = 0;
  }
  void push(const T& val) {
    if (!isFull()) {
      top++;
      data[top] = val;
    } 
    else {
      throw std::logic_error("ERROR in PUSH: Stack is full!");
    }
  };
  void pop() {
    if (!isEmpty()) {
      top--;
    }
    else {
      throw std::logic_error("ERROR in POP: Stack is empty!");
    }
  };
  void top() {
    std::cout << data[top] << std::endl;
  };


  friend std::ostream& operator<<(std::ostream& ostr, const Stack& s) {
    for (size_t i = 0; i < size; i++) {
      ostr << data[size] << std::endl;
    }
    return ostr;
  }


};

#endif