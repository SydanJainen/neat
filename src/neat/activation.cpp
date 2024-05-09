#include <cmath>
#include "neat/activation.h"

Activation::Activation(std::function<double(double)> activation_func,
                       std::optional<std::function<double(double)>> derivative_func)
    : activation_function(activation_func), derivative_function(derivative_func) {}

std::function<double(double)> sigmoid = [](double x) {
    return 1.0 / (1.0 + exp(-x));
};

std::function<double(double)> relu = [](double x) {
    return (x > 0) ? x : 0.0;
};
