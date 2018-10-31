#pragma once
#include "Graph.h"
#include "Path.h"
#include <assert.h>
#include <algorithm>

class ConstructionHeuristic
{
public:
	ConstructionHeuristic(const Graph& graph, double alpha) : graph(graph), alpha(alpha), path(graph) { assert(alpha <= 1 && 0<=alpha); };

	auto operator()()->Path;

	virtual ~ConstructionHeuristic();
private:
	const Graph& graph;
	Path path;
	double alpha;
	auto getNextVertex()->const Vertex&;
};

