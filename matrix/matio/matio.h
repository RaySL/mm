#pragma once

#include "matrix/matrix.h"

#include <iostream>
#include <iomanip>

template<typename T>
std::ostream& operator << (std::ostream& stream, Matrix<T> M){
  stream << std::setprecision(2) << std::fixed;

  stream << "[";

  for (int row = 0; row < M.rows(); row++){
    if (row > 0) stream << " ";
    stream << "[";

    for (int column = 0; column < M.columns(); column++){
      stream << std::setw(5) << M(column, row);
      if (column < M.columns()-1) stream << " ";
    }

    stream << "]";
    if (row < M.rows()-1) stream << "\n";
  }
  stream << "]";

  return stream;
}
