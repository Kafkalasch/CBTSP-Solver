#pragma once
#include "Path.h"

class PathAnalyzer
{
public:
	PathAnalyzer(const Path& graph) : path(path) {};
	~PathAnalyzer();
	
	bool isHamiltonian();
	bool isCyclic();

private:
	const Path& path;
};

