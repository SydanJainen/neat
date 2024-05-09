#ifndef NEURON_MUTATOR_H
#define NEURON_MUTATOR_H

#include "neurongene.h"
#include <functional>
#include <vector>

class NeuronMutator {
public:
    NeuronGene new_neuron(NeuronType type = NeuronType::Hidden);

private:
    std::function<double(double)> choose_random_activation();
    double get_random_bias();
};

#endif // NEURON_MUTATOR_H
