#pragma once
#include <string>

using std::string;

template <class T>
class ValidatorBase
{
public:
	ValidatorBase() {}
	virtual ~ValidatorBase() {}

	virtual string getError() = 0;
	virtual bool CheckValid(const T & data) = 0;
};

