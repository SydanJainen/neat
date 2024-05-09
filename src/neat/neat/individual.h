#pragma once

#include "genome.h"

class Individual {
public:
    Genome genome;
    double fitness;
    Individual() : genome(0, 0, 0, 0), fitness(0) {}
};
