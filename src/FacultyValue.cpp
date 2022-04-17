#include "FacultyValue.h"


FacultyValue::FacultyValue(int faculty)
	:m_Faculty(faculty)
{}

//--------------------------------------------------
FacultyValue::~FacultyValue()
{}

//--------------------------------------------------
void FacultyValue::setFaculty(int type)
{
	m_Faculty = type;
}

//--------------------------------------------------
int FacultyValue::getFaculty() const
{
	return m_Faculty;
}

//--------------------------------------------------
//read the number and insert it to the member
std::istream & operator>>(std::istream & in, FacultyValue & faculty)
{
	int n;
	in >> n;
	faculty.setFaculty(n);
	return in;
}

//--------------------------------------------------
//print the name of the Faculty by the Faculty value
std::ostream & operator<<(std::ostream & out, const FacultyValue & faculty)
{
	switch (faculty.getFaculty())
	{
	case 1:
		out << "Computer Sience";
		break;
	case 2:
		out << "Medicine";
		break;
	case 3:
		out << "Literature";
		break;
	default:
		out << faculty.getFaculty(); 
		break;
	}
	return out;
}

//--------------------------------------------------
// operator to be use in the range validator
bool operator>=(const FacultyValue & faculty1, const FacultyValue & faculty2)
{
	return faculty1.getFaculty() >= faculty2.getFaculty();
}

//--------------------------------------------------
// operator to be use in the range validator
bool operator<=(const FacultyValue & faculty1, const FacultyValue & faculty2)
{
	return faculty1.getFaculty() <= faculty2.getFaculty();
}
