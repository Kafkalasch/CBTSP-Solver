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
#include "GraphCompleter.h"
#include "ConstructionHeuristic.h"

using std::string;
using std::endl;
using namespace CBTSP;
using std::cout;
using std::endl;

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

	GraphImporter importer("test-instances\\0100.txt");
	Graph graph(importer.importGraph());

	cout << "Before completion: " << endl;
	cout << graph.print();
	(GraphCompleter(graph))();

	cout << "After completion: " << endl;
	cout << graph.print();

	auto startPath = ConstructionHeuristic(graph, 0.05)();
	cout << "Constructed path: " << endl;
	cout << startPath.print() <<endl;
	cout << "Path hamiltonian: " << startPath.isHamiltonian();

	std::cin.get();
}

