#pragma once

class MultyValidatorBase
{
public:
	MultyValidatorBase();
	virtual ~MultyValidatorBase() {}

	virtual bool checkFormValidator() = 0;
	virtual void UpdateFieldStat() = 0;
	bool getFormStat();

protected:
	bool m_valid ;
};

