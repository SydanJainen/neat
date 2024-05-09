#pragma once

#include "individual.h"
#include "activation.h"


NeuronGene crossover_neuron(const NeuronGene& first, const NeuronGene& second);
LinkGene crossover_link(const LinkGene& first, const LinkGene& second);
Genome crossover(const Individual& dominant, const Individual& recessive);
