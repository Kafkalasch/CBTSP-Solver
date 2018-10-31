#pragma once
#include "Vertex.h"
#include <unordered_set>
#include "Graph.h"

class Path
{
public:
	using const_iterator = std::vector<const Vertex*>::const_iterator;
	
	Path(const Graph& graph) : graph(graph) {};

	virtual ~Path();

	void addVertex(const Vertex& v);
	
	auto begin()const ->const_iterator { return const_iterator(path.begin()); }
	auto end()const ->const_iterator { return const_iterator(path.end()); }
	
	auto size()const->size_t { return path.size(); }
	auto back()const->const Vertex* { return path.back(); }

	bool contains(const Vertex& v) const { return vertexCounter.find(&v) != vertexCounter.end(); } 
	bool isHamiltonian() const ;
	bool isCyclic() const;

	auto print() const->std::string;
private:
	double cost = 0;
	const Graph& graph;
	bool multiVisit = false;

	std::vector<const Vertex*> path;
	std::unordered_map<const Vertex*,int> vertexCounter;
};


