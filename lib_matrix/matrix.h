// Copyright 2022 Marina Usova

#ifndef LIB_MATRIX_MATRIX_H_
#define LIB_MATRIX_MATRIX_H_

#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template <class T> class TDynamicVector;
template <class T> class TDynamicMatrix;

template <class T>
class TDynamicVector {
 protected:
  size_t sz;
  T* pMem;

 public:
  explicit TDynamicVector(size_t size = 1) : sz(size) {
    if (sz == 0)
      throw std::out_of_range("Vector size should be greater than zero");
    if (sz >= MAX_VECTOR_SIZE)
        throw std::out_of_range("Vector size should be lesser than 100000000");
    pMem = new T[sz];
  }

  TDynamicVector(T* arr, size_t s) : sz(s) {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  explicit TDynamicVector(const TDynamicVector& v) {
      sz = v.sz;
      pMem = new T[sz];
      std::memcpy(pMem, v.pMem, v.sz * sizeof(T));
  }

  explicit TDynamicVector(TDynamicVector&& v) noexcept {
      pMem = nullptr;
      swap(*this, v);
  }

  ~TDynamicVector() {
      pMem = nullptr;
      sz = 0;
  }

  TDynamicVector& operator=(const TDynamicVector& v) {
      if (this == &v)
          return *this;

      TDynamicVector tmp(v);
      swap(*this, tmp);
      return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept {
      if (this != &v) {
          delete[] pMem;
          swap(*this, v);
      }
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // indexing

  T& operator[](size_t ind) {
      if ((ind >= 0) && (ind <= this->sz)) {
          return pMem[ind];
      }
      else { throw std::exception("out of range"); }
  }

  const T& operator[](size_t ind) const {
      if ((ind >= 0) && (ind <= this->sz)) {
          return pMem[ind];
      }
      else { throw std::exception("out of range"); }
  }

  // indexing with control

  T& at(size_t ind) {
      if ((ind >= 0) && (ind <= this->sz)) {
          return pMem[ind];
      }
      else { throw std::exception("out of range"); }
  }

  const T& at(size_t ind) const {
      if ((ind >= 0) && (ind <= this->sz)) {
          return pMem[ind];
      }
      else { throw std::exception("out of range"); }
  }

  // comparisons

  bool operator==(const TDynamicVector& v) const noexcept {
      if (sz != v.sz)
          return false;

      for (size_t i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i])
              return false;
      }
      return true;
  }

  bool operator!=(const TDynamicVector& v) const noexcept {
      return !(*this == v);
  }

  // scalar operations

  TDynamicVector& operator+(int val) {
      for (int i = 0; i < sz; i++) {
          pMem[i] += val;
      }
      return *this;
  }

  TDynamicVector& operator-(double val) {
      for (int i = 0; i < sz; i++) {
          pMem[i] -= val;
      }
      return *this;
  }

  TDynamicVector& operator*(double val) {
      for (int i = 0; i < sz; i++) {
          pMem[i] *= val;
      }
      return *this;
  }

  // vector operations

  TDynamicVector& operator+(const TDynamicVector& v) {
      if (sz == v.sz) {
          TDynamicVector tmp;
          tmp.sz = sz;
          tmp.pMem = new T[sz];
          for (int i = 0; i < sz; i++) {
              tmp.pMem[i] = pMem[i] + v.pMem[i];
          }
          return tmp;
      }
      else { throw std::exception("the length of the vectors is different"); }

  }

  TDynamicVector& operator-(const TDynamicVector& v) {
      if (sz == v.sz) {
          TDynamicVector tmp(sz);
          for (int i = 0; i < sz; i++) {
             tmp.pMem[i] = pMem[i] - v.pMem[i];
          }
          return tmp;
      }
      else { throw std::exception("the length of the vectors is different"); }

  }

  T operator*(const TDynamicVector& v) noexcept(noexcept(int())) {
      if (sz == v.sz) {
          T tmp = 0;
          for (int i = 0; i < sz; i++) {
              tmp += pMem[i] * v.pMem[i];
          }
          return tmp;
      }
      else { throw std::exception("the length of the vectors is different"); }
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // input / output


  friend std::istream& operator>>(std::istream& istr, TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i];
    return istr;
  }

  friend std::ostream& operator<<(std::ostream& ostr, const TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' ';
    return ostr;
  }
};

template <class T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>> {
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;

 public:
  explicit TDynamicMatrix(size_t s = 1)
  : TDynamicVector<TDynamicVector<T>>(s) {
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // comparison

  bool operator==(const TDynamicMatrix& m) const noexcept {
      if (sz != m.sz) {
          return false;
      }
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != m.pMem[i]) {
              return false;
          }
      }

      return true;
  }

  // matrix-scalar operations

  TDynamicMatrix& operator*(const T& val) {
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] * val;
      }
      return tmp;
  }

  // matrix-vector operations

  TDynamicVector& operator*(const TDynamicVector& v) {
      TDynamicVector<T> tmp(sz);
      for (int j = 0; j < m_stl; j++)
          tmp.pMem[i] += pMem[i][j] * v.pMem[j];
      return tmp;
  }

  // matrix-matrix operations

  TDynamicMatrix& operator+(const TDynamicMatrix& m) {
      if (sz != m.sz) {
          throw std::exception("the sizes of the matrixes are different");
      }
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              tmp.pMem[i][j] = pMem[i][j] - m.pMem[i][j];
          }
      }
      return tmp;
  }

  TDynamicMatrix& operator-(const TDynamicMatrix& m) {
      if (sz != m.sz) {
          throw std::exception("the sizes of the matrixes are different");
      }
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              tmp.pMem[i][j] = pMem[i][j] - m.pMem[i][j];
          }
      }
      return tmp;
  }

  TDynamicMatrix& operator*(const TDynamicMatrix& m) {
      if (sz != m.sz) {
          throw std::exception("the sizes of the matrixes are different");
      }
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              tmp.pMem[i][j] = 0;
              for (int k = 0; k < sz; k++)
                  tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
          }
      }
      return tmp;
  }

  // input / output

  friend std::istream& operator>>(std::istream& istr, TDynamicMatrix& v) {
      for (int i = 0; i < v.sz; i++) {
          istr >> v.pMem[i];
      }
      return istr;
  }

  friend std::ostream& operator<<(std::ostream& ostr, const TDynamicMatrix& v) {
      for (int i = 0; i < v.sz; i++) {
          ostr << v.pMem[i] << std::endl;
      }
      return ostr;
  }
};

#endif  // LIB_MATRIX_MATRIX_H_
