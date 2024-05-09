template<typename FitnessT>
Individual Population::run(FitnessFn<FitnessT> compute_fitness, int num_generations) {
    for (int i = 0; i < num_generations; i++) {
        compute_fitness(individuals.begin(), individuals.end());
        update_best();
        individuals = reproduce();
    }
    return individuals.front();
}
