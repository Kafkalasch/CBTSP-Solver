#pragma once

#include "AStepFunction.h"

namespace CBTSP {
	template<class Solution>
	class NextImprovementStepFunction : public AStepFunction<Solution>
	{
	public:
		bool TryFindImprovement(
			const ANeighborhoodGeneratorFactory<Solution>& neighborhoodGenerator,
			const Solution& initialSolution,
			Solution* betterSolution) const override 
		{
			return initialSolution.IsStrictlyBetter(betterSolution);

		}
	};
	
}

