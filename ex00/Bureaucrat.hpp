#ifndef __BUREAUCRAT__H__
#define __BUREAUCRAT__H__
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		Bureaucrat & operator = (const Bureaucrat &bureaucrat);

		const std::string getName() const;
		int		getGrade() const;
		void	incremGrade(int quantity);
		void	decremGrade(int quantity);

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
					return "Grade you set is too low";
				}
		};
		
};

std::ostream	&operator << ( std::ostream &ostr, const Bureaucrat &bureaucrat );

#endif  //!__BUREAUCRAT__H__