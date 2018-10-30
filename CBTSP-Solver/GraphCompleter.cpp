#include "GraphCompleter.h"
#include <iostream>



void GraphCompleter::operator()()
{
	auto bigM = calcBigM();
	std::cout << "Big M is: " << bigM << std::endl;

	for (const auto& vertex : graph)
	{
		for (const auto& vertex2 : graph)
			if (!vertex2.isNeighbouredTo(vertex))
			{
				graph.addEdge(vertex, vertex2, bigM);
			}
	}
}

GraphCompleter::~GraphCompleter()
{
}

double GraphCompleter::calcBigM()
{
	double out = 1; // we calculate a majorant of 2M + 1

	for (const auto& vertex :graph)
		for (const auto& neighbour : vertex)
		{
			out += 2*std::abs(vertex.getDistanceTo(neighbour)); //intendetly counts edges multiple times - does not matter
		}
	return out;
}
