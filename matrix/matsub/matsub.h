#pragma once

#include "matrix/matrix.h"

/**
  * Straightforward matrix subtraction
**/

template <typename T>
Matrix<T>& operator - (Matrix<T>& A, Matrix<T> B) {
  assert(A.columns() == B.columns() && A.rows() == B.rows());

  Matrix<T>& M = (*new Matrix<T>(A.columns(), A.rows()));

  for (int column = 0; column < M.columns(); column++){
    for (int row = 0; row < M.rows(); row++){
      M(column, row) = A(column, row) - B(column, row);
    }
  }

  return M;
}
