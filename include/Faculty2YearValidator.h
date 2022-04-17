#pragma once
#include "MultyValidatorBase.h"

enum FacultyType { COMPUTER_SIENCE = 1 , MEDICINE, LITERATURE };

template < class T1,class T2>
class Faculty2YearValidator : public MultyValidatorBase
{
public:
	Faculty2YearValidator(T1* faculty, T2* year)
		: m_faculty(faculty), m_year(year) {};
	~Faculty2YearValidator() {};

	bool checkFormValidator();
	string getError();
	void UpdateFieldStat();

private:
	T1 * m_faculty;
	T2 * m_year;
};


//--------------------------------------------------
//check if Faculty and year are in line

template <typename T1, typename T2>
bool Faculty2YearValidator<T1,T2>::checkFormValidator()
{
	int faculty = m_faculty->getAnswer().getFaculty();
	int year = m_year->getAnswer();

	m_valid = true;
	switch (faculty)
	{
	case(COMPUTER_SIENCE):
		if (year > 4)
			m_valid = false;
		break;

	case(LITERATURE):
		if (year > 3)
			m_valid = false;
		break;

	case(MEDICINE):
		if (year > 7)
			m_valid = false;
		break;
	default :
		return false;
	}
	return m_valid;
}

//--------------------------------------------------
template <typename T1, typename T2>
string Faculty2YearValidator<T1, T2>::getError()
{
	return "\nFaculty and year don't match\n";
}

//--------------------------------------------------
//if nedded - set error message and set year and faculty as false
template <typename T1, typename T2>
void Faculty2YearValidator<T1, T2>::UpdateFieldStat()
{
	if (!m_valid)
	{
		std::cout << getError();
		m_faculty->setFieldStat(false);
		m_year->setFieldStat(false);
	}
}

