#include "Path.h"
#include <sstream>


Path::~Path()
{
}

bool Path::isHamiltonian()const
{
	return isCyclic() && !multiVisit;
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
	for (auto vertexIt = path.begin(); vertexIt != path.end(); ++vertexIt,++cnt)
	{
		out << (**vertexIt).getId();
		
		if (vertexIt != --path.end())
		{
			auto& nextVertex = **(vertexIt +1);
			auto isVirtualEdge = (**vertexIt).getDistanceTo(nextVertex) == graph.getBigM();
			out << (isVirtualEdge? " *> " : " -> ") ;
		}
		if (cnt % 15 == 0)
			out << std::endl;
	}
	return out.str();
}
