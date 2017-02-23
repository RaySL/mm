#include "matrix/matio/matio.h"
#include "matrix/matdet/matdet.h"

/*
Make IO files seperate -- done?
Make operators seperate from Implementations (in their own files)
Free matrix memory in delete (Is this necessary?)
*/

int main(int argc, char* argv[]){
  Matrix< Scalar<double> > A(2, 2, {
   1, 1,
   1, 0
  });


  std::cout << determinant(A) << std::endl;
  return 0;
}
