#pragma once
#include "ValidatorBase.h"
#include <iostream>

class FacultyValue 
{
public:
	FacultyValue(int faculty = 0);
	~FacultyValue();

	void setFaculty(int);
	int getFaculty() const;

private :
	int m_Faculty;
};

//operators for the class type
std::istream & operator >>(std::istream& , FacultyValue &);
std::ostream & operator <<(std::ostream&, const FacultyValue&);
bool operator>= (const FacultyValue& , const FacultyValue&);
bool operator<=(const FacultyValue& , const FacultyValue&);