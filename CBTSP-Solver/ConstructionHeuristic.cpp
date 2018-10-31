#include "ConstructionHeuristic.h"
#include <assert.h>
#include <stdio.h>

auto ConstructionHeuristic::operator()() -> Path
{
	if (path.size() == graph.size())
		return path;
	path.addVertex(*graph.begin());

	while (path.size() < graph.size())
	{
		auto& nextVertex = getNextVertex();
		path.addVertex(nextVertex);
	}
	return path;
}

ConstructionHeuristic::~ConstructionHeuristic()
{
}

auto ConstructionHeuristic::getNextVertex() -> const Vertex &
{
	assert(path.size() > 0);
	auto& lastVertex = *path.back();

	int numberOfOpenVertices = graph.size() - path.size();
	assert(numberOfOpenVertices > 0);

	int numberOfAllowedVertices = static_cast<int>(std::max(alpha * (numberOfOpenVertices), 1.0));

	int loopCounter = 0;
	int verticesIdx = std::rand() % numberOfAllowedVertices;

	for (const auto& neighbour : lastVertex)
	{
		if (path.contains(neighbour))  //we want to construct a hamiltonian cycle
			continue;
		if (loopCounter == verticesIdx)
			return neighbour;
		++loopCounter;
	}
}
