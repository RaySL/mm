#include "network.h"

Network::Network(int layers){
  m_layers = layers;
  m_weights = new Matrix< Scalar<double> >[layers];
  m_biases = new Matrix< Scalar<double> >[layers];

  srand(time(NULL));
}

Network::~Network(){
  delete[] m_weights;
  delete[] m_biases;
}

Matrix< Scalar<double> > Network::feedForward(Matrix< Scalar<double> > activation){
  for (int layer = 0; layer < m_layers; layer++){
    activation = m_weights[layer] * activation;

    activation = transpose(activation);

    activation = activation + m_biases[layer];

    activation = elementwise(activation, sigmoid);
  }

  return activation;
}

void Network::stochasticGradientDescent(std::vector<Sample> samples, int batches, int epochs, double rate){
  int bsize = samples.size() / batches;

  for (int epoch = 0; epoch < epochs; epoch++){

    //Fix this disgusting mess
    for (int i = 0; i < samples.size(); i++){
      int r = rand() % samples.size();
      Sample t = samples[i];
      samples[i].input = samples[r].input;
      samples[i].output = samples[r].output;
      samples[r].input = t.input;
      samples[r].output = t.output;
    }

    for (int batch = 0; batch < batches; batch++){
      std::vector<Sample> section(std::begin(samples) + batch * bsize, std::begin(samples) + batch * bsize + bsize);
      updateSection(section, rate);
    }
  }
}

void Network::updateSection(std::vector<Sample> samples, double rate){
  rate /= samples.size();

  Matrix< Scalar<double> >* nabla_weight = new Matrix< Scalar<double> >[m_layers];
  Matrix< Scalar<double> >* nabla_bias   = new Matrix< Scalar<double> >[m_layers];

  for (int layer = 0; layer < m_layers - 1; layer++){
    nabla_bias[layer]   = *new Matrix< Scalar<double> > (m_biases [layer].columns(), m_biases [layer].rows());
    nabla_weight[layer] = *new Matrix< Scalar<double> > (m_weights[layer].columns(), m_weights[layer].rows());
  }

  for (int sample = 0; sample < samples.size(); sample++){
    DeltaNabla delta_nabla = backPropagate(samples[sample]);

    for (int layer = 0; layer < m_layers - 1; layer++){
      nabla_bias[layer]   = nabla_bias[layer]   + delta_nabla.biases[layer];
      nabla_weight[layer] = nabla_weight[layer] + delta_nabla.weights[layer];
    }
  }

  for (int layer = 0; layer < m_layers - 1; layer++){
    Matrix< Scalar<double> > temp;
    temp = (-rate) * nabla_bias[layer];
    m_biases[layer]  = m_biases[layer]  + temp;
    temp = (-rate) * nabla_weight[layer];
    m_weights[layer] = m_weights[layer] + temp;
  }
}

DeltaNabla Network::backPropagate(Sample sample){
  Matrix< Scalar<double> >* nabla_weight = new Matrix< Scalar<double> >[m_layers];
  Matrix< Scalar<double> >* nabla_bias   = new Matrix< Scalar<double> >[m_layers];

  Matrix< Scalar<double> > activation = sample.input;
  Matrix< Scalar<double> >* activations = new Matrix< Scalar<double> >[m_layers];
  activations[0] = sample.input;

  //Matrix< Scalar<double> > z;
  Matrix< Scalar<double> >* zs = new Matrix< Scalar<double> >[m_layers];

  for (int layer = 0; layer < m_layers - 1; layer++){
    zs[layer] = m_weights[layer] * activation + m_biases[layer];
    //z = weights[i].transpose().mul(activation.transpose()).add(biases[i]);
    //zs[layer] = z;
    activation = elementwise(zs[layer], sigmoid);
    activations[layer + 1] = activation;
  }

  Matrix< Scalar<double> > delta = activation - sample.output;
  delta = hadamard(delta, elementwise(zs[m_layers - 1], sigmoid_prime));

  nabla_bias[m_layers - 1] = delta;
  nabla_weight[m_layers - 1] = transpose(delta) * activations[m_layers - 2];

  Matrix< Scalar<double> > sp;
  for (int layer = m_layers - 2; layer >= 1; layer--){
    Matrix< Scalar<double> > sp = elementwise(zs[layer], sigmoid_prime);
    delta = hadamard(sp, transpose(m_weights[layer + 1]) * delta);

    nabla_bias[layer]   = delta;
    nabla_weight[layer] = delta * transpose(activations[layer - 1]);
  }

  return {nabla_bias, nabla_weight};
}




double sigmoid(double z){
  return 1 / (1 + exp(-z));
};

double sigmoid_prime(double z){
  return sigmoid(z) * (1 - sigmoid(z));
};
