#include "matrix/matrix.h"
#include "scalar/scaops/scaops.h"

/**
  * Obtain the inverse matrix through Gauss-Jordan elimination
**/

template<typename T>
Matrix<T>& inverse(Matrix<T> A){
  assert(A.columns() == A.rows());

  //Create an identity matrix of the same size (delegate later)
  Matrix<T>& B = *new Matrix<T>(A.columns(), A.rows());
  for (int i = 0; i < A.columns(); i++){
    B(i, i) = 1;
  }


  //Swap rows to ensure a pivot can be found for each row
  bool singular = 1;
  for (int column = 0; column < A.columns(); column++){
    for (int row = column; row < A.rows(); row++){
      if (A(column, row) != 0){
        if (row == column) continue;

        for (int i = 0; i < A.columns(); i++){
          T temp = A(i, row);
          A(i, row) = A(i, column);
          A(i, column) = temp;

          temp = B(i, row);
          B(i, row) = B(i, column);
          B(i, column) = temp;
        }

        singular = 0;
        break;
      }
    }
  }

  if (singular){
    //throw? -- decide on error handling
    std::cout << "Error: matrix is singular" << std::endl;
    return *new Matrix<T>(A.columns(), A.rows());
  }

  for (int column = 0; column < A.columns(); column++){
    for (int row = 0; row < A.rows(); row++){
      if (row == column) continue;
      if (A(column, row) == 0) continue;

      T factor = A(column, row) / A(column, column);
      for (int i = 0; i < A.rows(); i++){
        A(i, row) -= factor * A(i, column);
        B(i, row) -= factor * B(i, column);
      }
    }
  }

  for (int row = 0; row < A.rows(); row++){
    T scale = A(row, row);
    for (int column = 0; column < A.columns(); column++){
      B(column, row) /= scale;
    }
  }

  return B;
}
