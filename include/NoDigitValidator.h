#pragma once
#include "ValidatorBase.h"
#include <string>

class NoDigitValidator :public ValidatorBase <std::string>
{
public:

	NoDigitValidator();
	~NoDigitValidator();

	bool CheckValid(const std::string & name);
	string getError();

private:

};

