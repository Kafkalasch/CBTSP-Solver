#pragma once

#include "ANeighborhoodGenerator.h"

namespace CBTSP {
	template<class Solution>
	class ANeighborhoodGeneratorFactory
	{
	public:
		
		virtual ANeighborhoodGenerator<Solution> Create(const Solution& initialSolution) const = 0;

	};
}