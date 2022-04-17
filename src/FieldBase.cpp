#include "FieldBase.h"


FieldBase::FieldBase()
{}

//--------------------------------------------------
void FieldBase::setFieldStat(bool stat)
{
	m_isValid = stat;
}

//--------------------------------------------------
bool FieldBase::getStat()
{
	return m_isValid;
}
