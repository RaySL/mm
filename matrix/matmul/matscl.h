#include "matrix/matrix.h"

template <typename T>
Matrix<T> operator * (T A, Matrix<T> B) {
  Matrix<T> M(B.columns(), B.rows());

  for (int column = 0; column < M.columns(); column++){
    for (int row = 0; row < M.rows(); row++){
      M(column, row) *= A;
    }
  }

  return M;
}
