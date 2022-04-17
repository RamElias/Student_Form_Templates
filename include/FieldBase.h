#pragma once
#include <iostream>

class FieldBase
{
public:
	FieldBase();
	virtual ~FieldBase() {}

	virtual void fillField() = 0;
	virtual bool checkField() = 0;
	virtual void printField(std::ostream&) = 0;

	void setFieldStat(bool);
	bool getStat();
	
protected:
	bool m_isValid = false;
};

