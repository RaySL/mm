#pragma once

#include "matrix/matrix.h"
#include "matrix/matio/matio.h"
#include "scalar/scaops/scaops.h"

/**
  * Obtain the determinant through Gaussian elimination
**/

/* Needs further testing -- may be correct */

template<typename T>
T determinant(Matrix<T> M){
  assert(M.rows() == M.columns());

  T det = 1;

  //Convert the matrix to row echelon form one column at a time
  for (int column = 0; column < M.columns(); column++){
    bool allZeros = 1;

    for (int row = column; row < M.rows(); row++){
      if (M(column, row) == 0) continue;
      allZeros = 0;

      if (row == column) break;

      //Swapping two rows of a matrix will negate the determinant
      det *= -1;

      //Swap row "row" with row "column"
      for (int i = 0; i < M.columns(); i++){
        T temp = M(i, row);
        M(i, row) = M(i, column);
        M(i, column) = temp;
      }
      std::cout << "Swapped:\n" << M << "\n";

      break;
    }

    //If all elements below and including the diagonal are zero, the determinant must be zero
    if (allZeros) return 0;


    for (int row = column + 1; row < M.rows(); row++){
      if (M(column, row) == 0) break;

      T factor = M(column, row) / M(column, column);
      std::cout << "factor: " << factor << "\n";

      std::cout << "Before:\n" << M << "\n";
      for (int i = column; i < M.columns(); i++){
        M(i, row) -= factor * M(i, column);
      }
      std::cout << "Scaled:\n" << M << "\n";

      /*det *= -1;
      for (int i = 0; i < M.columns(); i++){
        T temp = M(i, row);
        M(i, row) = M(i, column);
        M(i, column) = temp;
    }*/
      //std::cout << "Swapped:\n" << M << "\n";
    }
  }

  //Because the matrix is in row-echelon form, the determinant is equal to the trace
  for (int i = 0; i < M.columns(); i++){
    det *= M(i, i);
  }

  return det;
}
