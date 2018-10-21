#pragma once
#include "Graph.h"
#include <fstream>

namespace CBTSP {

	class GraphImporter
	{
	public:
		GraphImporter(const std::string filepath) : infile(filepath) {}
		~GraphImporter();
		// prevent copying due to open file handle
		GraphImporter(const GraphImporter&) = delete;
		void operator=(const GraphImporter&) = delete;

		Graph importGraph();

	private:
		std::ifstream infile;
		
		void readFirstLine();
		Graph readGraph();

	};
}

