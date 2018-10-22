#pragma once
#include "Vertex.h"
#include <unordered_set>
//#include "IteratorCollection.h"

namespace CBTSP {

	class Graph
	{
	public:
		using const_iterator = const_iterator_Graph<Vertex>;

		auto begin()const->const_iterator { return const_iterator(vertices.begin()); }
		auto end() const->const_iterator { return const_iterator(vertices.end()); }

		void addEdge(const Vertex&, const Vertex&, double weight);
		auto find(int id) const ->const Vertex*;
		
		auto print() const->std::string;

		//friend std::ostream& operator<<(std::ostream& os, const Graph&);
	private:
		std::unordered_map<int, Vertex> vertices; //id to vertex

		void createIfNotExistent(const Vertex& v);
	};
}
