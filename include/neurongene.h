#ifndef NEURONGENE_H
#define NEURONGENE_H

enum class NeuronType {
    Input,
    Output,
    Hidden
};

#include "activation.h"

class NeuronGene {
public:
  int neuron_id;
  double bias;
  Activation activation;
  NeuronType type;

  NeuronGene(int id, double b, Activation a, NeuronType neuronType = NeuronType::Input) : neuron_id(id), bias(b), activation(a), type(neuronType) {}
};

#endif // NEURONGENE_H