#pragma once

#include "matrix/matrix.h"

/**
  * Ridiculously simple and inefficient matrix multiplication
**/

template <typename T>
Matrix<T>& operator * (Matrix<T>& A, Matrix<T>& B) {
  assert(A.columns() == B.rows());

  Matrix<T>& M = *(new Matrix<T>(B.columns(), A.rows()));

  for (int column = 0; column < B.columns(); column++){
    for (int row = 0; row < A.rows(); row++){
      T sum(0);
      for (int i = 0; i < A.columns(); i++){
        sum += A(i, row) * B(column, i);
      }
      M(column, row) = sum;
    }
  }

  return M;
}
