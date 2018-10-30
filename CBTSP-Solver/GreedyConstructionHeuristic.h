#pragma once
#include "ConstructionHeuristic.h"

class GreedyConstructionHeuristic : public ConstructionHeuristic
{
public:
	GreedyConstructionHeuristic(const Graph& graph) : ConstructionHeuristic(graph, 0) {};
	virtual ~GreedyConstructionHeuristic();
};

