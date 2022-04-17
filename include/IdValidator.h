#pragma once
#include "ValidatorBase.h"
#include <cstdint>
#include <string>

using std::string;


class IDValidator :public ValidatorBase <uint32_t>
{
public:
	IDValidator();
	~IDValidator();

	bool CheckValid(const uint32_t & id);
	std::string getError();
};

