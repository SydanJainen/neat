#include "../include/linkmutator.h"
#include <random>

LinkGene LinkMutator::new_value(int input_id, int output_id) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(mean, std_dev);
    double weight = distribution(gen);
    return LinkGene(LinkId(input_id, output_id), weight, true);
}
