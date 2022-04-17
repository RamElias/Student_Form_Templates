#include "Form.h"

Form::Form()
{
}

//--------------------------------------------------
Form::~Form()
{
}

//--------------------------------------------------
//add a field pointer to the member
void Form::addField(FieldBase *field)
{
	m_Fields.push_back(field);
}

//--------------------------------------------------
//add a MultyValidatorBase pointer to the member
void Form::addValidator(MultyValidatorBase *Mulval)
{
	m_MultyValidators.push_back(Mulval);
}

//--------------------------------------------------
//cheking the status ao the field and if false read from the user the answer
void Form::fillForm()
{
	for (size_t i = 0; i < m_Fields.size(); i++)
		if(!m_Fields[i]->getStat()) //gets from filed base ths stat
			m_Fields[i]->fillField(); //will read ansewer from the user
}

//--------------------------------------------------
//cheking the status of the form -the fileds and the mul validator
bool Form::validateForm()
{
	bool formStat = checkFields(); //checks all the files

	if (formStat) // if fileds are o.k
		return checkMulValidator(); // check all the mul validator

	return formStat; 
}

//--------------------------------------------------
//cheking the status of the form fileds - needs to go throw all 
// the vector hens the 'checkField' will update any false with error msg
bool Form::checkFields()
{
	bool stat = true;
	for (size_t i = 0; i < m_Fields.size(); i++)
		if (!m_Fields[i]->checkField()) //return the status of the filed
			stat = false;

	return stat;
}

//--------------------------------------------------
//cheking the status of the form mul validator - needs to go throw all 
// the vector hens the 'checkFormValidator' will update any false with error msg
bool Form::checkMulValidator()
{
	bool stat = true;
	
	for (size_t i = 0; i < m_MultyValidators.size(); i++)
		if (!m_MultyValidators[i]->checkFormValidator()) //return the status of the filed
			stat = false;

	return stat;
}

//--------------------------------------------------
//print all the form ques + answer + error (if nedded)
void Form::printForm(std::ostream & os) const
{
	for (size_t i = 0; i < m_Fields.size(); i++)
		m_Fields[i]->printField(os); 

	std::cout << std::endl;

	
	for (size_t i = 0; i < m_MultyValidators.size(); i++)
			m_MultyValidators[i]->UpdateFieldStat();//if false will print the error
}

//--------------------------------------------------
std::ostream & operator<<(std::ostream& os, const Form& form)
{
	form.printForm(os);
	return os;
}
