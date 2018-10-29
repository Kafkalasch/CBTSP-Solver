#pragma once
#include "ASolution.h"

namespace CBTSP
{
	class Solution : public ASolution<Solution>
	{
	public:
		Solution();
		virtual ~Solution();
	};
}

