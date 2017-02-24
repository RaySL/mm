#pragma once

#include "matrix/matrix.h"

/**
  * Element-wise application of a function (or lambda)
**/

template<typename T, typename F>
Matrix<T>& elementwise(Matrix<T>& A, F lambda){
  Matrix<T>& M = *new Matrix<T>(A.columns(), A.rows());

  for (int column = 0; column < M.columns(); column++){
    for (int row = 0; row < M.rows(); row++){
      M(column, row) = lambda(A(column, row));
    }
  }

  return M;
}
