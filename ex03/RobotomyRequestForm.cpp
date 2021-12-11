#include "RobotomyRequestForm.hpp"

/*
** Methods
*/
void	RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
	int	num;

	if (!this->getIsSigned())
	{
		std::cout << "Cant execute form without signing\n";
		throw Form::CantExecuteException();
	}
	if (executor.getGrade() > this->getGradeExecute())
		throw Form::GradeTooLowException();

	srand(time(0));
	num = rand() % 10;
	if (num < 5)
		std::cout << "brrrrr " << this->getTarget() << " has been robotomized\n";
	else
		std::cout << "brrrrr " << this->getTarget() << " robotomize failed\n";
}

std::string	RobotomyRequestForm::getTarget() const
{
	return _target;
}
/*
** Constructors and destructors
*/
RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy", 72, 45)
{
	this->_target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform) : Form()
{
	*this = robotomyrequestform;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &robotomyrequestform)
{
	this->_target = robotomyrequestform.getTarget();
	return *this;
}
