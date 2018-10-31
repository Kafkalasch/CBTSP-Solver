#include "Path.h"
#include <sstream>


Path::~Path()
{
}

bool Path::isHamiltonian()const
{
	return false;
}

bool Path::isCyclic()const
{
	return vertexCounter.size() == graph.size();
}

void Path::addVertex(const Vertex& v)
{
	if (size() != 0)
		cost += path.back()->getDistanceTo(v);
	path.push_back(&v);
	
	auto it = vertexCounter.find(&v);
	if (it == vertexCounter.end())
		vertexCounter[&v] = 1;
	else
	{
		vertexCounter[&v] += 1;
		multiVisit = true;
	}
}

auto Path::print() const -> std::string
{
	std::stringstream out;

	int cnt = 1;
	for (const auto& vertex : path)
	{
		out << vertex->getId();
		if (cnt != path.size())
			out << " - > ";
		if (cnt % 15 == 0)
			out << std::endl;
		++cnt;
	}
	return out.str();
}
