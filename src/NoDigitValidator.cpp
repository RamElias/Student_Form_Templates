#include "NoDigitValidator.h"


NoDigitValidator::NoDigitValidator()
{}

//--------------------------------------------------
NoDigitValidator::~NoDigitValidator()
{}

//--------------------------------------------------
//check if name contain numbers
bool NoDigitValidator::CheckValid(const std::string & name)
{
	for (size_t i = 0; i < name.size(); i++)
		if (isdigit(name[i]))
			return false;

	return true;
}

//--------------------------------------------------
string NoDigitValidator::getError()
{
	return "Can't contain digits";
}
