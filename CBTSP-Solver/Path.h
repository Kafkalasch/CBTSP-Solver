#pragma once
#include "Vertex.h"


class Path
{
public:
	using const_iterator = std::vector<const Vertex*>::const_iterator;
	Path();
	virtual ~Path();

	auto begin()const ->const_iterator { return const_iterator(path.begin()); }
	auto end()const ->const_iterator { return const_iterator(path.end()); }
	
	auto size()const->size_t { return path.size(); }
	auto back()const->const Vertex* { return path.back(); }
	void addVertex(const Vertex& v);
private:
	int cost = 0;
	std::vector<const Vertex*> path;
};


