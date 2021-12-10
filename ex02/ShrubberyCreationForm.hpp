#ifndef __SHRUBBERYCREATIONFORM__H__
#define __SHRUBBERYCREATIONFORM__H__

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm :public Form
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform);
		~ShrubberyCreationForm();

		void	execute( const Bureaucrat &executor ) const;
		std::string	getTarget() const;

		ShrubberyCreationForm & operator = (const ShrubberyCreationForm &shrubberycreationform);
};


#endif  //!__SHRUBBERYCREATIONFORM__H__