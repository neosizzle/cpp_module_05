#ifndef __PRESIDENTIALPARDONFORM__H__
#define __PRESIDENTIALPARDONFORM__H__
#include <iostream>
#include "Form.hpp"
class PresidentialPardonForm :public Form
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform);
		~PresidentialPardonForm();

		void	execute( const Bureaucrat &executor ) const;
		std::string	getTarget() const;

		PresidentialPardonForm & operator = (const PresidentialPardonForm &presidentialpardonform);
};

#endif  //!__PRESIDENTIALPARDONFORM__H__