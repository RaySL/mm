#pragma once

#include "scalar/scalar.h"


template<typename T>
Scalar<T> operator * (Scalar<T> A, Scalar<T> B){
  return Scalar<T>((T)A * (T)B);
};

template<typename T>
Scalar<T> operator * (Scalar<T> A, T B){
  return Scalar<T>((T)A * B);
};

template<typename T>
Scalar<T> operator * (T A, Scalar<T> B){
  return Scalar<T>(A * (T)B);
};


template<typename T>
void operator *= (Scalar<T>& A, Scalar<T> B){
  A = A * B;
};

/*template<typename T>
void operator *= (Scalar<T>& A, T B){
  A = A * B;
};*/

template<typename T, typename N>
void operator *= (Scalar<T>& A, N B){
  A = A * B;
};


template<typename T>
void operator *= (T& A, Scalar<T> B){
  A = A * (T)B;
};
