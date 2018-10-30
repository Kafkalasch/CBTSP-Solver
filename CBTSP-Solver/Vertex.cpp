#include "Vertex.h"
#include <sstream>

bool Vertex::isNeighbouredTo(const Vertex & node) const
{
	return neighbours.find(&node) != neighbours.end();
}

double Vertex::getDistanceTo(const Vertex & node) const
{
	auto it = neighbours.find(&node);

	if (it == neighbours.end())
		return std::numeric_limits<double>::max();
	else
	{
		return it->second;
	}
}

void Vertex::addNeighbour(const Vertex & neighbour, double weight)
{
	neighbours.insert(std::make_pair(&neighbour, weight));
	dist2Neighbour.insert(std::make_pair(weight, &neighbour));

}

void Vertex::eraseNeighbour(const Vertex & neighbour)
{
	auto it = neighbours.find(&neighbour);
	if (it != neighbours.end())
		neighbours.erase(it);
	
	for (auto it = dist2Neighbour.begin(); it != dist2Neighbour.end(); ++it)
	{
		if (it->second == &neighbour)
		{
			dist2Neighbour.erase(it);
			break;
		}
	}
}
auto Vertex::print() const -> std::string
{
	std::stringstream out;
	out << this->getId() << " -> " << "( ";
	for (const auto& neighbour : *this)
	{
		out << neighbour.getId() << " ";
	}
	out << ")";
	return out.str();

	/*std::ostream & operator<<(std::ostream & os, const Vertex & vertex)
	{
		os << "V" << vertex.getId();
		return os;
	}*/
}
