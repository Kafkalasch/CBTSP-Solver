#pragma once

#include "ANeighborhoodGeneratorFactory.h"

namespace CBTSP {
	template<class Solution>
	class AStepFunction
	{
	public:
		// returns true if a better solution was found, false, otherwise
		virtual bool TryFindImprovement(const ANeighborhoodGeneratorFactory<Solution>& neighborhoodGenerator, const Solution& initialSolution, Solution* betterSolution ) const = 0;
	};
}