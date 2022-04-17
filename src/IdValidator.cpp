#include "IdValidator.h"


IDValidator::IDValidator()
{}

//--------------------------------------------------
IDValidator::~IDValidator()
{}

//--------------------------------------------------
//calculate if ID number is o.k by algorithem
bool IDValidator::CheckValid(const uint32_t & id)
{
		std::string temp = std::to_string(id);

		if (temp.size() != 9)
			return false;

		int counter = 0;
		int num;

		for (unsigned int i = 0; i < temp.size(); i++)
		{
			num = ((int)temp[i] - 48)*((i % 2) + 1);
			counter += (num > 9) ? num - 9 : num;
		}

		return (counter % 10 == 0);
}

//--------------------------------------------------
string IDValidator::getError()
{
	return "Wrong control digit";
}
