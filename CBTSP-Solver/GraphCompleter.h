#pragma once
#include "Graph.h"


class GraphCompleter
{
public:
	GraphCompleter(Graph& graph) : graph(graph) {};

	void operator()();

	~GraphCompleter();
private:
	Graph& graph;
	double calcBigM();
};

