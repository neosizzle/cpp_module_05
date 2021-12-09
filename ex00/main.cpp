#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat crat("john", 69);
	std::cout << crat << "\n";

	std::cout << "Incrementing grade by 60..\n";
	crat.incremGrade(60);
	std::cout << crat << "\n";

	std::cout << "Decrementing grade by 60..\n";
	crat.decremGrade(60);
	std::cout << crat << "\n";

	try
	{
		std::cout << "Decrementing grade by 600 in try catch..\n";
		crat.decremGrade(600);
		std::cout << crat << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Decrementing grade by 600 with no try catch..\n";
	crat.decremGrade(600);
	std::cout << crat << "\n";

	return 0;
}
