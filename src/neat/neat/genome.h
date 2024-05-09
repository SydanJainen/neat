#pragma once

#include <vector>
#include <optional>
#include "neurongene.h"
#include "link.h"

class Genome {
    public:
        Genome(int id = 0, int num_inputs = 0, int num_outputs = 0, int num_hidden = 0);
        
        std::vector<NeuronGene> neurons;
        std::vector<LinkGene> links;

        static int next_genome_id;

        std::optional<NeuronGene> find_neuron(int id) const;
        std::vector<int> make_inputs_ids() const;
        std::vector<int> make_hidden_ids() const;
        std::vector<int> make_outputs_ids() const;
        std::vector<NeuronGene> get_neurons_of_type(NeuronType type) const;
        std::optional<LinkGene> Genome::get_link(int input_id, int output_id) const;

        void add_neuron(const NeuronGene& neuron);
        void add_link(const LinkGene& link);
        const std::vector<LinkGene>& get_links() const;

        static int get_next_genome_id();

    private:
        std::vector<int> input_ids;
        std::vector<int> output_ids;
        std::vector<int> hidden_ids;
        
        int genome_id;
};