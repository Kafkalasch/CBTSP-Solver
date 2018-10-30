#pragma once


namespace CBTSP {
	template<class Solution>
	class ASolution
	{
	public:
		virtual bool IsStrictlyBetterThan(const Solution& otherSolution) const = 0;
	};
}