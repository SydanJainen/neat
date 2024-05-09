#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "NeuronInput.h"
#include "Activation.h"  // Assume Activation struct is defined elsewhere

struct Neuron {
    int neuron_id; 
    Activation activation;
    double bias;
    std::vector<NeuronInput> inputs;

    Neuron(int id, double b, Activation act, std::vector<NeuronInput> in)
    : neuron_id(id), bias(b), activation(act), inputs(std::move(in)) {}

};

#endif // NEURON_H
