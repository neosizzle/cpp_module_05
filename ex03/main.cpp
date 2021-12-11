#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include  "Intern.hpp"

void	print(std::string str)
{
	std::cout << str << "\n";
}

void	print_nonl(std::string str)
{
	std::cout << str ;
}

int main()
{
	Bureaucrat crat("highlvl", 1);
	Bureaucrat crat1("midlvl", 75);
	Bureaucrat crat2("lowlvl", 150);
	Intern intern;

	print("=====SHRUBBERY FORM TESTS====");
	try
	{
		Form *newform = intern.makeForm("shrubbery creation", "Bender");
		
		crat.signForm(*newform);
		print("");
		crat.executeForm(*newform);
		print("");
		crat1.executeForm(*newform);
		delete newform;
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");
	print("=====ROBOTOMY FORM TESTS====");
	try
	{
		Form *newformrobo = intern.makeForm("robotomy request", "Bender");
		
		crat.signForm(*newformrobo);
		print("");
		crat.executeForm(*newformrobo);
		delete newformrobo;
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");
	print("=====PRESIDENTIAL PARDON TESTS====");
	try
	{
		Form * newformpred = intern.makeForm("presidental pardon", "Bender");
		
		crat.signForm(*newformpred);
		print("");
		crat.executeForm(*newformpred);
		delete newformpred;
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");
	print("=====GRADE TOO LOW TEST====");
	Form *newformpred =  intern.makeForm("presidental pardon", "Bender");
	try
	{		
		crat1.signForm(*newformpred);
		crat2.executeForm(*newformpred);
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
		delete newformpred;
	}
	print("============================");
	print("=====NO SIGN TEST====");
	newformpred =  intern.makeForm("presidental pardon", "Bender");
	try
	{		
		crat2.executeForm(*newformpred);
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
		delete newformpred;
	}
	print("============================");
	print("=====UNKNOWN TEST====");
	newformpred =  intern.makeForm("presion", "Bender");
	delete newformpred;
	print("============================");

	return 0;
}
