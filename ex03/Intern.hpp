#ifndef __INTERN__H__
#define __INTERN__H__

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &intern);

		Intern & operator = (const Intern &intern);

		Form	*makeForm(std::string formname, std::string target);
};



#endif  //!__INTERN__H__