#include "Vertex.h"
#include "Graph.h"
#include <iostream>
#include <sstream>

void Graph::addEdge(const Vertex & v1, const Vertex & v2, double weight)
{
	createIfNotExistent(v1);
	createIfNotExistent(v2);

	auto it1 = vertices.find(v1.getId());
	auto it2 = vertices.find(v2.getId());

	it1->second.addNeighbour(it2->second, weight);
	it2->second.addNeighbour(it1->second, weight);
}

auto Graph::find(int id) const -> const Vertex *
{
	auto it = vertices.find(id);
	if (it == vertices.end())
		return nullptr;
	else
		return &it->second;
}

void Graph::createIfNotExistent(const Vertex & v)
{
	auto it = vertices.find(v.getId());
	if (it == vertices.end())
	{
		vertices.insert(std::make_pair(v.getId(), v));
	}
}

auto Graph::print() const -> std::string
{
	std::stringstream out;
	for (const auto& vertex : *this)
	{
		out << vertex.print() << std::endl;
	}
	return out.str();
}
	

