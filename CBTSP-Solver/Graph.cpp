#include "Vertex.h"
#include "Graph.h"
#include <iostream>
#include <sstream>

void Graph::addEdge(const Vertex & v1, const Vertex & v2, double weight)
{
	createIfNotExistent(v1);
	createIfNotExistent(v2);

	auto& vertex1 = vertices.find(v1.getId())->second;
	auto& vertex2 = vertices.find(v2.getId())->second;

	if (vertex1.isNeighbouredTo(vertex2)) //we do not allow multigraphs
		return;
	if (&vertex1 == &vertex2) //we do not allow self-referencing-edges
		return; 

	vertex1.addNeighbour(vertex2, weight);
	vertex2.addNeighbour(vertex1, weight);
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
	

