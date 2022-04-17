#pragma once
#include "ValidatorBase.h"

template < class T>
class RangeValidator :public ValidatorBase <T>
{
public:
	RangeValidator(T min, T max) 
		:m_min(min),m_Max(max) {}
	~RangeValidator() {}

	bool CheckValid(const T & data);
	string getError();
	
private:
	T m_min;
	T m_Max;
};

//--------------------------------------------------
//return if the value as nedded or not
template <typename T>
inline bool RangeValidator<T>::CheckValid(const T & data)
{
	return (data >= m_min && data <= m_Max);
}
//--------------------------------------------------
template <typename T>
string RangeValidator<T>::getError()
{
	return "Out of range";
}