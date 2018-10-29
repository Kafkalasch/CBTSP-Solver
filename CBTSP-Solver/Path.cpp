#include "Path.h"



Path::Path()
{
}


Path::~Path()
{
}

void Path::addVertex(const Vertex& v)
{
	if (size() != 0)
		cost += path.back()->getDistanceTo(v);
	path.push_back(&v);
}
