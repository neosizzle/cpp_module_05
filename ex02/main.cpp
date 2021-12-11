#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

	print("=====SHRUBBERY FORM TESTS====");
	try
	{
		ShrubberyCreationForm newform("targetasdf");
		
		crat.signForm(newform);
		print("");
		crat.executeForm(newform);
		print("");
		crat1.executeForm(newform);

	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");
	print("=====ROBOTOMY FORM TESTS====");
	try
	{
		RobotomyRequestForm newformrobo("targetasdf");
		
		crat.signForm(newformrobo);
		print("");
		crat.executeForm(newformrobo);
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");
	print("=====PRESIDENTIAL PARDON TESTS====");
	try
	{
		PresidentialPardonForm newformpred("targetasdf");
		
		crat.signForm(newformpred);
		print("");
		crat.executeForm(newformpred);
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");
	print("=====GRADE TOO LOW TEST====");
	try
	{
		PresidentialPardonForm newformpred("targetasdf");
		
		crat1.signForm(newformpred);
		crat2.executeForm(newformpred);
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");
	print("=====NO SIGN TEST====");
	try
	{
		PresidentialPardonForm newformpred("targetasdf");
		
		crat2.executeForm(newformpred);
	}
	catch (const std::exception& e)
	{
		std::cout << "error from catch : " << e.what() << "\n";
	}
	print("============================");

	return 0;
}
