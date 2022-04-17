#pragma once
#include <vector>
#include <memory>
#include "FieldBase.h"
#include "MultyValidatorBase.h"

using std::vector;

class Form
{
public:
	Form();
	~Form();

	void addField(FieldBase* );
	void addValidator(MultyValidatorBase* );
	void fillForm();
	bool validateForm();
	bool checkFields();
	bool checkMulValidator();
	void printForm(std::ostream& ) const;

private:
	vector <FieldBase*> m_Fields;
	vector <MultyValidatorBase *> m_MultyValidators;
};

std::ostream & operator<<(std::ostream& ,const Form& );
