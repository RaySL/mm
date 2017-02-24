#pragma once

#include "matrix/matrix.h"
#include "matrix/matmul/matmul.h"
#include "matrix/matmul/hadamard.h"
#include "matrix/matmul/matscl.h"
#include "matrix/transpose.h"
#include "matrix/matadd/matadd.h"
#include "matrix/matsub/matsub.h"
#include "matrix/matelm/matelm.h"
#include "scalar/scalar.h"

#include <cmath>
#include <vector>
#include <random>
#include <time.h>


struct Sample {
  Matrix< Scalar<double> >& input;
  Matrix< Scalar<double> >& output;
};

struct DeltaNabla {
  Matrix< Scalar<double> >* biases;
  Matrix< Scalar<double> >* weights;
};


/*
Add initialization with layer sizes
*/


class Network {
public:
  Network(int layers);
  ~Network();

  Matrix< Scalar<double> > feedForward(Matrix< Scalar<double> > activation);

  void stochasticGradientDescent(std::vector<Sample> samples, int batches, int epochs, double rate);

  void updateSection(std::vector<Sample> section, double rate);

  DeltaNabla backPropagate(Sample sample);

private:

  int m_layers;
  Matrix< Scalar<double> >* m_weights;
  Matrix< Scalar<double> >* m_biases;
};

double sigmoid(double);
double sigmoid_prime(double);
