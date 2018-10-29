#pragma once
#include <unordered_map>
#include <string>
#include "IteratorCollection.h"

namespace CBTSP {



	class Vertex
	{
	public:
		Vertex(int id) : id(id) {};

		using const_iterator = const_iterator_Vertex<Vertex>;

		auto begin() const ->const_iterator { return const_iterator(neighbours.begin()); }
		auto end() const ->const_iterator { return const_iterator(neighbours.end()); }

		int getId() const { return id; }
		bool isNeighbouredTo(const Vertex& node) const;
		double getDistanceTo(const Vertex& node) const;

		void addNeighbour(const Vertex& neighbour, double weight);
		void eraseNeighbour(const Vertex& neighbour);

		auto print()const->std::string;
	private:
		const int id;
		std::unordered_map<const Vertex*, double> neighbours;  //Überlegung: vielleicht auch noch die inverse Abbildung abspeichern als multimap<double,const Vertex&> um die Suche nach kleinsten, bezw. größten Gewichten zu beschleunigen
		//auto getNeighbours() const -> const std::unordered_map<const Vertex*, double>& { return neighbours; } //not nice
	};

}




//namespace std
//{
//	template<>
//	struct hash<Vertex>
//	{
//		size_t operator()(const Vertex& node) const
//		{
//			return hash<int>()(node.getId());
//		}
//	};
//}