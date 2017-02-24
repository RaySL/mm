#pragma once

#include "matrix/matrix.h"
#include "scalar/scaops/scaops.h"

template <typename T, typename U>
Matrix<T> operator * (U A, Matrix<T>& B) {
  Matrix<T> M(B);

  for (int column = 0; column < M.columns(); column++){
    for (int row = 0; row < M.rows(); row++){
      M(column, row) *= A;
    }
  }

  return M;
}
