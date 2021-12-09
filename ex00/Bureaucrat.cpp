#include "Bureaucrat.hpp"

/*
** Methods
*/

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incremGrade(int quantity)
{
	if (_grade - quantity < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= quantity;
}

void Bureaucrat::decremGrade(int quantity)
{
	if (_grade + quantity > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += quantity;
}

/*
** Constrctors and destructors
*/
Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade  > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << "name is const, only copying grade...\n";
	this->_grade = bureaucrat.getGrade();
	return *this;
}

std::ostream & operator<<(std::ostream &ostr, const Bureaucrat &bureaucrat)
{
	ostr << bureaucrat.getName() << ", Bureaucrat grade " << bureaucrat.getGrade();
	return ostr;
}