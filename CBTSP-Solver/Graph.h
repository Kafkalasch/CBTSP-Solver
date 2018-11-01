#pragma once
#include "Vertex.h"
#include <unordered_set>
//#include "IteratorCollection.h"


	class Graph
	{
	public:
		using const_iterator = const_iterator_Graph<Vertex>;

		Graph() = default;
		Graph(Graph&&) = default;
		Graph(const Graph&) = delete; //copying this graph directly would result in wrong pointer states - delete constructor

		auto begin()const->const_iterator { return const_iterator(vertices.begin()); }
		auto end() const->const_iterator { return const_iterator(vertices.end()); }

		void addEdge(const Vertex&, const Vertex&, double weight);
		auto find(int id) const ->const Vertex*;
		auto size()const -> size_t { return vertices.size(); }
		
		void setBigM(double bigM) { this->bigM = bigM; }
		double getBigM()const { return bigM; }

		auto print() const->std::string;
	private:
		std::unordered_map<int, Vertex> vertices; //id to vertex
		double bigM = std::numeric_limits<double>::min();
		void createIfNotExistent(const Vertex& v);
	};

