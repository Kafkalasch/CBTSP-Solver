// CBTSP-Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <unordered_map>
#include "Vertex.h"
#include "Graph.h"









int main()
{
    std::cout << "Hello World!\n"; 
	Graph graph;
	graph.addEdge(Vertex(1), Vertex(2), 1.5);
	graph.addEdge(Vertex(1), Vertex(3), 2.5);
	graph.addEdge(Vertex(2), Vertex(3), 3.5);
	for (int i = 3; i < 10000; ++i)
		graph.addEdge(Vertex(i % 10), Vertex(i), i);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


