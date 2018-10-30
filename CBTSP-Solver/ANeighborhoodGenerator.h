#pragma once

namespace CBTSP {
	template<class Solution>
	class ANeighborhoodGenerator
	{
	public:
		ANeighborhoodGenerator(const Solution& initialSolution) : initialSolution(initialSolution) {}
		// returns true if the next element could be generated
		// return false, otherwise (i.e. there is no element left)
		virtual bool CreateNextElement(Solution& nextElement) = 0;

	protected:
		const Solution& initialSolution;
	};
}