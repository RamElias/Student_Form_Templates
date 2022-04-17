#pragma once
#include "FieldBase.h"
#include "ValidatorBase.h"

const std::string FIELD_LINE = '+' + std::string(50, '-') + '+' + '\n';

template < class T>
class Field : public FieldBase
{
public:
	Field(std::string question) :m_ques(question) {};
	~Field() {};
	
	void addValidator(ValidatorBase <T>* val);
	void fillField();
	bool checkField();
	void printField(std::ostream & os);
	string getQuestion();
	void setAnswer(const T & newAnswer);
	T getAnswer()const;

private :
	std::string m_ques;
	std::string m_error;
	T m_answer {} ;
	vector <ValidatorBase <T>*> m_Validators;
};

//--------------------------------------------------
// add validator to the m_Validators vector
template <typename T>
void Field<T>::addValidator(ValidatorBase <T>* val)
{
	m_Validators.push_back(val);
}

//--------------------------------------------------
//print question and read answer from the user (sa filed nedded)
template <typename T>
void Field<T>::fillField()
{
	std::cout << FIELD_LINE;
	std::cout << m_ques << std::endl;
	std::cin >> m_answer;
}

//--------------------------------------------------
//check if al the filed are valied and return bool
template <typename T>
bool Field<T>::checkField()
{
	m_isValid = true;
	for (size_t i = 0; i < m_Validators.size(); i++)
		if (!m_Validators[i]->CheckValid(m_answer)) //if valid
		{
			m_error = m_Validators[i]->getError(); //init the error msg
			m_isValid = false;
			return m_isValid;
		}
	return m_isValid;
}

//--------------------------------------------------
//print question and answer from the user (sa filed nedded)
template <typename T>
void Field<T>::printField(std::ostream & os)
{
	os << std::endl << FIELD_LINE;
	os << m_ques << " = " << m_answer;
	if (!m_isValid) 
		os << "           " << m_error; //if wrong
}

//--------------------------------------------------
template <typename T>
std::string Field<T>::getQuestion()
{
	return m_ques;
}

//--------------------------------------------------
template <typename T>
void Field<T>::setAnswer(const T & newAnswer)
{
	m_answer = newAnswer;
}

//--------------------------------------------------
template <typename T>
T Field<T>::getAnswer()const
{
	return m_answer;
}