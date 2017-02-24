//need comments

template<typename T>
Matrix<T>::Matrix():
  Matrix(0, 0)
{};

template<typename T>
Matrix<T>::Matrix(int columns, int rows){
  m_columns = columns;
  m_rows = rows;

  m_data = new T[m_columns * m_rows];
};

template<typename T>
Matrix<T>::Matrix(int columns, int rows, std::initializer_list<T> elements):
  Matrix(columns, rows)
{
  assert(m_columns * m_rows == elements.size());
  std::memcpy(m_data, elements.begin(), m_columns * m_rows * sizeof(T));
};

template<typename T>
Matrix<T>::Matrix(Matrix<T>& M):
  Matrix(M.columns(), M.rows())
{
  std::memcpy(m_data, M.data(), m_columns * m_rows * sizeof(T));
};


template<typename T>
Matrix<T>::~Matrix(){

};


template<typename T>
T* Matrix<T>::data(){
  return m_data;
};

template<typename T>
int Matrix<T>::columns(){
  return m_columns;
};

template<typename T>
int Matrix<T>::rows(){
  return m_rows;
};



template<typename T>
T& Matrix<T>::operator ()(int column, int row){
  return m_data[column + row * m_columns];
}
