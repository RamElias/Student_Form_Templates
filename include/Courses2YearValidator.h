#pragma once
#include "MultyValidatorBase.h"

template < class T1,class T2>
class Courses2YearValidator : public MultyValidatorBase
{
public:
	Courses2YearValidator(T1* course,T2* year)
		: m_course(course), m_year(year) {};
	~Courses2YearValidator() {};

	bool checkFormValidator();
	string getError();
	void UpdateFieldStat();

private:
	T1 * m_course;
	T2 * m_year;
};


//--------------------------------------------------
//check if cours and year are in line
template <typename T1 , typename T2>
bool Courses2YearValidator<T1, T2>::checkFormValidator()
{
	m_valid = false;
	int course = m_course->getAnswer();
	int year = m_year->getAnswer();

	if (year < 1 || year > 7 || course < 2 || course > 10)
		return m_valid;

	else if ((year == 1 || year == 2) && (course >= 2 && course <= 6))
		m_valid = true;

	else if ((year == 3 || year == 4) && (course >= 2 && course <= 10))
		m_valid = true;

	else if (year >=5 && (course >= 2 && course <= 8))
		m_valid = true;

	return m_valid;
}
//--------------------------------------------------
template <typename T1, typename T2>
string Courses2YearValidator<T1, T2>::getError()
{
	return "\nCourses and year don't match\n";
}
//--------------------------------------------------
//if nedded - set error message and set year and cours as false
template <typename T1, typename T2>
void Courses2YearValidator<T1, T2>::UpdateFieldStat()
{
	if (!m_valid)
	{
		std::cout << getError();
		m_course->setFieldStat(false);
		m_year->setFieldStat(false);
	}
}