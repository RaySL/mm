/**
  * Scalar constructor
  * Takes an initial magnitude for the scalar
**/
template<typename T>
Scalar<T>::Scalar(T m){
  magnitude = m;
};

/**
  * Scalar constructor
  * Assumes that the magnitude is numerical, sets it to zero
**/
template<typename T>
Scalar<T>::Scalar(){
  magnitude = 0;
};

/**
  * Scalar destructor
**/
template<typename T>
Scalar<T>::~Scalar(){

};


/**
  * Scalar cast to type of magnitude
**/
template<typename T>
Scalar<T>::operator T() const {
  return magnitude;
};


/**
  * Scalar assignment
**/
template<typename T>
template<typename U>
Scalar<T>& Scalar<T>::operator = (Scalar<U> B) {
  magnitude = (T)(U)B;
  return *this;
};

template<typename T>
template<typename U>
Scalar<T>& Scalar<T>::operator = (U B) {
  magnitude = (T)B;
  return *this;
};
