#pragma once
#include <unordered_map>


class Vertex
{
public:
	Vertex(int id) : id(id) {};

	class const_iterator
	{
		using const_iterator_intern = std::unordered_map<const Vertex*, double>::const_iterator;
	public:
		const_iterator(const_iterator_intern it) : it(it) {};
		const_iterator operator++() { ++it; return *this;}
		const_iterator operator--() { --it; return *this; }
		const Vertex& operator*() const { return *it->first; }
		friend bool operator==(const_iterator l, const_iterator r) { return l.it == r.it; }
	private:
		std::unordered_map<const Vertex*, double>::const_iterator it;
	};

	const_iterator begin() const { return const_iterator(neighbours.begin()); }
	const_iterator end() const { return const_iterator(neighbours.end()); }

	int getId() const { return id; }
	bool isNeighbouredTo(const Vertex& node) const;
	double getDistanceTo(const Vertex& node) const;

	void addNeighbour(const Vertex& neighbour, double weight);
	void eraseNeighbour(const Vertex& neighbour);
private:
	const int id;
	std::unordered_map<const Vertex*, double> neighbours;
	//auto getNeighbours() const -> const std::unordered_map<const Vertex*, double>& { return neighbours; }
};

namespace std
{
	template<>
	struct hash<Vertex>
	{
		size_t operator()(const Vertex& node) const
		{
			return hash<int>()(node.getId());
		}
	};
}