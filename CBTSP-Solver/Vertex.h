#pragma once
#include <unordered_map>
#include <string>
#include "IteratorCollection.h"
#include <map>

class Vertex
{
public:
	Vertex(int id) : id(id) {};

	using const_iterator = const_iterator_Vertex<Vertex>;

	auto begin() const ->const_iterator { return const_iterator(dist2Neighbour.begin()); }
	auto end() const ->const_iterator { return const_iterator(dist2Neighbour.end()); }

	int getId() const { return id; }
	bool isNeighbouredTo(const Vertex& node) const;
	double getDistanceTo(const Vertex& node) const;

	void addNeighbour(const Vertex& neighbour, double weight);
	void eraseNeighbour(const Vertex& neighbour);

	auto print()const->std::string;
private:
	const int id;
	std::unordered_map<const Vertex*, double> neighbours;  
	std::multimap<double, const Vertex*> dist2Neighbour;
};
