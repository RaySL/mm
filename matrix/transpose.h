#pragma once

#include "matrix/matrix.h"

/**
  * Matrix transposition
  * Create an in-place implementation
**/

template<typename T>
Matrix<T>& transpose(Matrix<T>& M){
  Matrix<T>& A = *new Matrix<T>(M.rows(), M.columns());

  for (int column = 0; column < M.columns(); column++){
    for (int row = 0; row < M.rows(); row++){
      A(row, column) = M(column, row);
    }
  }

  return A;
}
