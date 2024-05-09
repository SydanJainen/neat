#ifndef CYCLE_CHECK_H
#define CYCLE_CHECK_H

#include "genome.h"
#include <vector>
#include <stack>

bool check_cycle(const Genome& genome, int input_id, int output_id);

#endif // CYCLE_CHECK_H
