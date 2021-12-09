#ifndef __FORM__H__
#define __FORM__H__
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		bool		_is_signed;
		const std::string	_name;
		const int			_grade_sign;
		const int			_grade_execute;

	public:
		Form();
		Form(std::string name, int grade_sign, int grade_execute);
		Form(const Form &form);
		~Form();

		Form & operator = (const Form &form);

		void			beSigned(const Bureaucrat &bureaucrat);
		int				getGradeSign() const;
		int				getGradeExecute() const;
		std::string		getName() const;
		bool			getIsSigned() const;


		class GradeTooHighException : public std::exception
		{

			public:
				virtual const char* what() const throw()
				{
					return "Grade you set is too high";
				}
		};

		class GradeTooLowException : public std::exception
		{

			public:
				virtual const char* what() const throw()
				{
					return "Grade you set is too low or not high enough";
				}
		};
		
};

std::ostream	&operator << ( std::ostream &ostr, const Form &form);
#endif  //!__FORM__H__