#pragma once
#include "ValidatorBase.h"

template < class T>
class MinValidator :public ValidatorBase <short>
{
public:
	MinValidator(int min)
		:m_min(min){};
	~MinValidator() {};

	bool CheckValid(const T & data);
	string getError();

private:
	int m_min;

};

//--------------------------------------------------
//return if the value as nedded or not
template <typename T>
inline bool MinValidator<T>::CheckValid(const T & data)
{
	return !(data < m_min);
}

//--------------------------------------------------
template <typename T>
string MinValidator<T>::getError()
{
	return "Out of range";
}