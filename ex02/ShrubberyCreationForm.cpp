#include "ShrubberyCreationForm.hpp"

/*
** Methods
*/
void	ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
	if (!this->getIsSigned())
		throw Form::CantExecuteException();
	if (executor.getGrade() > this->getGradeExecute())
		throw Form::GradeTooLowException();



	// Create and open a text file
	std::ofstream NewFile(this->getTarget() + "_shrubbery");

	// Write to the file
	NewFile << "       _-_\n";
	NewFile << "    /~~   ~~\\\n";
	NewFile << " /~~         ~~\\\n";
	NewFile << "{               }\n";
	NewFile << " \\  _-     -_  /\n";
	NewFile << "_- -   | | _- _\n";
	NewFile << "  _ -  | |   -_\n";
	NewFile << "      // \\\n";

	// Close the file
	NewFile.close();

	std::cout << "shrubbery created at : " << this->getTarget() + "_shrubbery\n";
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}
/*
** Constructors and destructors
*/
ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery", 145, 137)
{
	this->_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform) : Form()
{
	*this = shrubberycreationform;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &shrubberycreationform)
{
	this->_target = shrubberycreationform.getTarget();
	return *this;
}
