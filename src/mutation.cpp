#include <genome.h>
#include <linkmutator.h>
#include <functions.h>
#include <neuronmutator.h>
#include <optional> // Required for std::optional

void mutate_add_link(Genome &genome) {
    // Get neuron IDs for inputs, outputs.
    auto input_ids = genome.make_inputs_ids();
    auto output_ids = genome.make_outputs_ids();
    int hidden_size = genome.neurons.size() - input_ids.size() - output_ids.size();

    // Choosing a random input or hidden neuron (excluding output neurons)
    int input_index = rand() % (input_ids.size() + hidden_size);
    int input_id = input_index < input_ids.size() ? input_ids[input_index] : input_ids.size() + input_index;

    // Choosing a random output or hidden neuron (can't be an input neuron)
    int output_index = rand() % (hidden_size + output_ids.size()) + input_ids.size();
    int output_id = output_index < (input_ids.size() + hidden_size) ? output_index : output_ids[output_index - input_ids.size() - hidden_size];

    // Check if a link already exists
    if (auto link_opt = genome.get_link(input_id, output_id); link_opt.has_value()) {
        link_opt->is_enabled = true; // Re-enable the link if it exists
        return;
    }

    // Check if the link would create a cycle in the network
    if (check_cycle(genome, input_id, output_id)) {
        return;
    }

    // Create a new link if no cycle is detected and the link does not exist
    LinkMutator link_mutator;
    LinkGene new_link = link_mutator.new_value(input_id, output_id);
    genome.add_link(new_link);
}


void mutate_remove_link(Genome &genome){
    if (genome.links.size() == 0) {
        return;
    }
    int link_index = rand() % genome.links.size();
    genome.links[link_index].is_enabled = false;
    genome.links.erase(genome.links.begin() + link_index);
}

void mutate_add_hidden_neuron( Genome &genome){
    if (genome.links.size() == 0) {
        return;
    }
    LinkGene &link = genome.links[rand() % genome.links.size()];
    genome.links[link.link_id.input_id].is_enabled = false;

    NeuronMutator neuron_mutator = NeuronMutator();
    NeuronGene new_neuron = neuron_mutator.new_neuron();
    genome.add_neuron(new_neuron);

    LinkId link_id = link.link_id;
    double weight = link.weight;

    genome.add_link(LinkGene(LinkId(link_id.input_id, new_neuron.neuron_id), 1.0, true));
    genome.add_link(LinkGene(LinkId(new_neuron.neuron_id, link_id.output_id), weight, true));
    
}

bool is_hidden_neuron(const Genome &genome, int neuron_id){
    int incoming = 0;
    int outgoing = 0;
    for (const LinkGene &link : genome.links) {
        if (link.link_id.output_id == neuron_id) {
            incoming++;
        }
        if (link.link_id.input_id == neuron_id) {
            outgoing++;
        }
    }
    return incoming > 0 && outgoing > 0;
}

void mutate_remove_hidden_neuron(Genome &genome){
    if (genome.neurons.size() == 0) {
        return;
    }
    //take all hidden neurons
    std::vector<int> hidden_neurons;
    for (const NeuronGene &neuron : genome.neurons) {
        if (is_hidden_neuron(genome, neuron.neuron_id)) {
            hidden_neurons.push_back(neuron.neuron_id);
        }
    }
    if (hidden_neurons.size() == 0) {
        return;
    }
    
    int neuron_index = rand() % hidden_neurons.size();
    int neuron_id = hidden_neurons[neuron_index];
    //disable all links connected to the neuron
    for (LinkGene &link : genome.links) {
        if (link.link_id.input_id == neuron_id || link.link_id.output_id == neuron_id) {
            link.is_enabled = false;
        }
    }
    //remove the neuron
    for (int i = 0; i < genome.neurons.size(); i++) {
        if (genome.neurons[i].neuron_id == neuron_id) {
            genome.neurons.erase(genome.neurons.begin() + i);
            break;
        }
    }
}