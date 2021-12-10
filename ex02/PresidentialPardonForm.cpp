#include "PresidentialPardonForm.hpp"

/*
** Methods
*/
void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	if (!this->getIsSigned())
		throw Form::CantExecuteException();
	if (executor.getGrade() > this->getGradeExecute())
		throw Form::GradeTooLowException();

	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox\n";

}

std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}
/*
** Constructors and destructors
*/
PresidentialPardonForm::PresidentialPardonForm() : Form("robotamy", 72, 45)
{
	this->_target = "";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("robotamy", 72, 45)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform) : Form()
{
	*this = presidentialpardonform;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &presidentialpardonform)
{
	this->_target = presidentialpardonform.getTarget();
	return *this;
}
