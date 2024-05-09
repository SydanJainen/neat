#include "../include/functions.h"
#include <limits>
#include <algorithm>

bool check_cycle(const Genome& genome, int input_id, int output_id) {
    std::vector<int> index(genome.neurons.size(), -1);
    std::vector<int> lowlink(genome.neurons.size(), -1);
    std::stack<int> dfs_stack;
    int index_counter = 0;

    // Initialize starting node
    index[input_id] = lowlink[input_id] = index_counter++;
    dfs_stack.push(input_id);

    while (!dfs_stack.empty()) {
        int current_id = dfs_stack.top();
        dfs_stack.pop();

        for (const LinkGene& link : genome.links) {
            if (link.link_id.input_id == current_id) {
                int neighbor_id = link.link_id.output_id;

                if (index[neighbor_id] == -1) { // Unvisited neighbor
                    index[neighbor_id] = lowlink[neighbor_id] = index_counter++;
                    dfs_stack.push(neighbor_id);

                    lowlink[current_id] = std::min(lowlink[current_id], lowlink[neighbor_id]);
                    if (lowlink[current_id] == index[neighbor_id]) {
                        return true; // Cycle found
                    }
                } else if (link.is_enabled) { // Visited and on current path (potential cycle)
                    lowlink[current_id] = std::min(lowlink[current_id], index[neighbor_id]);
                    if (lowlink[current_id] == index[neighbor_id]) {
                        return true; // Cycle found
                    }
                }
            }
        }
    }
    return false;
}
