#ifndef _SCALAR_H_
#define _SCALAR_H_

#include <iostream>

template<typename T>
class Scalar {
public:
  Scalar(T magnitude);
  Scalar();
  ~Scalar();

  operator T() const;

  template<typename U>
  Scalar<T>& operator = (Scalar<U> B);
  template<typename U>
  Scalar<T>& operator = (U B);

private:
  T magnitude;
};

#include "scalar.tpp"

#endif /* end of include guard: _SCALAR_H_ */
