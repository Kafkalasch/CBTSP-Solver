// CBTSP-Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include "Vertex.h"
#include "Graph.h"
#include "GraphImporter.h"
#include <fstream>
#include <sstream>
#include <string>

using std::string;
using std::endl;
using namespace CBTSP;

void testSimpleGraph() {
	Graph graph;
	graph.addEdge(Vertex(1), Vertex(2), 1.5);
	graph.addEdge(Vertex(1), Vertex(3), 2.5);
	graph.addEdge(Vertex(2), Vertex(3), 3.5);
	for (int i = 3; i < 10000; ++i)
		graph.addEdge(Vertex(i % 10), Vertex(i), i);
}

int main()
{
    std::cout << "Hello World!\n"; 

	GraphImporter importer("test-instances\\tiny.txt");
	Graph graph = importer.importGraph();

	std::cin.get();

}

