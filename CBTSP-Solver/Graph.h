#pragma once
#include "Vertex.h"
#include <unordered_set>

namespace CBTSP {
	class Graph
	{
	public:
		void addEdge(const Vertex&, const Vertex&, double weight);
		auto find(int id) const ->const Vertex*;
		
		//friend std::ostream& operator<<(std::ostream& os, const Graph&);
	private:
		std::unordered_map<int, Vertex> vertices; //id to vertex

		void createIfNotExistent(const Vertex& v);
	};
}
