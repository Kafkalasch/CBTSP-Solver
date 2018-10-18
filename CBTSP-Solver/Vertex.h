#pragma once


class Vertex
{
public:
	Vertex(int id) : id(id) {};
	int getId() const { return id; }
	auto getNeighbours() const -> const std::unordered_map<Vertex, double>& { return neighbours; }
	bool isNeighbour(const Vertex& node) const;
	double getDistanceTo(const Vertex& node) const;

private:
	const int id;
	std::unordered_map<Vertex, double> neighbours;
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