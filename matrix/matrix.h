#ifndef _MAT_H_
#define _MAT_H_

#include <initializer_list>
#include <cassert>
#include <cstring>

//need method to create distinctive matrices

template <typename T>
class Matrix {
public:
  Matrix(int columns, int rows);
  Matrix(int columns, int rows, std::initializer_list<T> elements);
  Matrix(Matrix<T>& M);
  ~Matrix();

  T* data();
  int columns();
  int rows();

  T& operator() (int column, int row);

private:
  unsigned int m_columns, m_rows;
  T* m_data;

};

#include "matrix.tpp"

#endif
