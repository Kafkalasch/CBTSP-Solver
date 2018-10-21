#include "GraphImporter.h"
#include <iostream>
#include <sstream>

namespace CBTSP {
	GraphImporter::~GraphImporter()
	{
		infile.close();
	}
	Graph GraphImporter::importGraph()
	{
		readFirstLine();
		Graph graph = readGraph();
		return graph;
	}

	void GraphImporter::readFirstLine()
	{
		std::string firstLine;
		std::getline(infile, firstLine);
		if (!infile)
		{
			std::cout << "Could not read the first line of the instance file" << std::endl;
		}
	}

	Graph GraphImporter::readGraph()
	{
		Graph graph;

		std::string line;
		while (std::getline(infile, line))
		{
			std::istringstream iss(line);

			int id1, id2, weight;
			if (!(iss >> id1 >> id2 >> weight))
			{
				std::cout << "Could not parse the line '" << line << "'" << std::endl;
			}
			Vertex v1(id1);
			Vertex v2(id2);

			graph.addEdge(v1, v2, weight);
		}
		return graph;
	}
}


