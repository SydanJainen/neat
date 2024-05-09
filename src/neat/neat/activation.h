#pragma once

#include <functional>
#include <optional>

class Activation {
public:
    std::function<double(double)> activation_function;
    std::optional<std::function<double(double)>> derivative_function;

    Activation(std::function<double(double)> activation_function,
               std::optional<std::function<double(double)>> derivative_function = std::nullopt);
};

extern std::function<double(double)> sigmoid;
extern std::function<double(double)> relu;

