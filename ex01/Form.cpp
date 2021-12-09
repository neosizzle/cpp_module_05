#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** Methods
*/
void			Form::beSigned(const Bureaucrat&bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_sign)
	{
		this->_is_signed = true;
		std::cout << bureaucrat << " signs " << *this << "\n";
		// std::cout << "Form " << this->_name << " of grade " << this->_grade_sign << " has been signed by " << bureaucrat.getName() << " of grade " << bureaucrat.getGrade() << "\n";
	}
	else
	{
		std::cout << bureaucrat << " cannot sign " << *this << "because grade too low\n";
		throw Form::GradeTooLowException();
	}
}

int				Form::getGradeSign() const
{
	return _grade_sign;
}

int				Form::getGradeExecute() const
{
	return _grade_execute;
}

std::string		Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _is_signed;
}


/*
** Constrctors and destructors
*/
Form::Form() :  _is_signed(false), _name(""), _grade_sign(150), _grade_execute(150)
{

}

Form::Form(std::string name, int grade_sign, int grade_execute) : _is_signed(false), _name(name), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	if (grade_sign < 1 || _grade_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_sign  > 150 || grade_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form) : _grade_sign(form.getGradeSign()), _grade_execute(form.getGradeExecute())
{
	*this = form;
}

Form::~Form()
{

}

Form & Form::operator=(const Form &form)
{
	this->_is_signed = form.getIsSigned();
	std::cout << "gradesign, gradeexecute and name is const, only copying issigned...\n";
	return *this;
}

std::ostream & operator<<(std::ostream &ostr, const Form &form)
{
	ostr << "Form name : " << form.getName() << ", Sign grade : " << form.getGradeSign() << ", Execute grade : " << form.getGradeExecute() <<
	" Is signed : " << form.getIsSigned();
	return ostr;
}