#ifndef __ROBOTOMYREQUESTFORM__H__
#define __ROBOTOMYREQUESTFORM__H__
#include "Form.hpp"
#include <stdlib.h>
class RobotomyRequestForm :public Form
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform);
		~RobotomyRequestForm();

		void	execute( const Bureaucrat &executor ) const;
		std::string	getTarget() const;

		RobotomyRequestForm & operator = (const RobotomyRequestForm &robotomyrequestform);
};

#endif  //!__ROBOTOMYREQUESTFORM__H__