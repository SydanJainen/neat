#ifndef LINK_MUTATOR_H
#define LINK_MUTATOR_H

#include "link.h"

class LinkMutator {
public:
    LinkGene new_value(int input_id, int output_id);

private:
    double mean = 0.0; // Mean of the Gaussian distribution
    double std_dev = 1.0; // Standard deviation of the Gaussian distribution
};

#endif // LINK_MUTATOR_H
