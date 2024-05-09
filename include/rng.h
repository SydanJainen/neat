#ifndef RNG_H
#define RNG_H

#include <random>
#include <iterator>

class Rng {
private:
    std::mt19937 rng_engine;

public:
    Rng() : rng_engine(std::random_device{}()) {}

    int get_random_int(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max - 1);
        return dist(rng_engine);
    }

    double get_random_double(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng_engine);
    }

    template<typename Iterator>
    Iterator choose_randomly(Iterator start, Iterator end) {
        std::uniform_int_distribution<> dist(0, std::distance(start, end) - 1);
        std::advance(start, dist(rng_engine));
        return start;
    }
};

#endif // RNG_H
