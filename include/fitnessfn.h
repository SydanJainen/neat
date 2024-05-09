#ifndef FITNESS_FN_H
#define FITNESS_FN_H

#include "individual.h"
#include <algorithm>

template<typename Iterator>
class FitnessFn {
public:
    void operator()(Iterator start, Iterator end) {
        std::for_each(start, end, [](Individual& ind) {
            // Example fitness computation: simply counts the number of active neurons
            ind.fitness = std::count_if(ind.genome.neurons.begin(), ind.genome.neurons.end(), 
                                        [](const NeuronGene& ng) { return ng.is_active(); });
        });
    }
};

#endif // FITNESS_FN_H
