#include "Intern.hpp"

/*
** Methods
*/
Form	*Intern::makeForm(std::string formname, std::string target)
{
	Form	*res = 0;

	std::string formStrings[] = 
	{
		"presidental pardon",
		"robotomy request",
		"shrubbery creation"
	};

	Form	*forms[] = 
	{
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};

	int	i;

	i = -1;
	while (++i < 3)
	{
		if (formname == formStrings[i])
			res = forms[i];
		else
			delete forms[i];
	}
	if (!res)
	{
		std::cout << "Intern does not know what form he should create\n";
		return 0;
	}
	std::cout << "Intern creates " << *res << "\n";
	return res;
}

/*
** Cons and desc
*/
Intern::Intern(){}
Intern::~Intern(){}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern & Intern::operator = (const Intern &intern)
{
	(void) intern;
	return *this;
}