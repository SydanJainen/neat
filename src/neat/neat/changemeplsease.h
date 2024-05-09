#pragma once

#include <vector>
#include <functional>
#include <optional>
#include <vector>
#include <stack>
#include <random>
#include <variant>
#include "rng.h"

static int m_genome_indexer = 0;

class DoubleConfig {
public:
  DoubleConfig(double init_mean = 0.0, double init_stdev = 1.0,
               double mutation_power = 1.2, double min_val = -20.0,
               double max_val = 20.0, double mutation_rate = 0.2,
               double replace_rate = 0.05)
      : init_mean(init_mean), init_stdev(init_stdev), mutation_power(mutation_power),
        min_val(min_val), max_val(max_val), mutation_rate(mutation_rate),
        replace_rate(replace_rate) {}

  double new_value() const {
    Rng rng;
    return clamp(rng.next_gaussian(init_mean, init_stdev));
  }

  double mutate_delta(double value) const {
    Rng rng;
    double delta = clamp(rng.next_gaussian(0.0, mutation_power));
    return clamp(value + delta);
  }

private:

  std::default_random_engine rng();
  double init_mean;
  double init_stdev;
  double mutation_power;
  double min_val;
  double max_val;
  double mutation_rate;
  double replace_rate;

  double clamp(double value) const {
    return std::min(std::max(value, min_val), max_val);
  }
};
