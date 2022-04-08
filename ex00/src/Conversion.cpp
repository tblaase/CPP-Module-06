/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:37:12 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/08 11:56:21 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

// static std::string types[] = {"char", "int", "float", "double", "impossible", "nan"};

// Constructors
Conversion::Conversion()
{
	std::cout << "Conversion Default Constructor called" << std::endl;
	/*CODE*/
}

Conversion::Conversion(const std::string input): _input(input)
{
	std::cout << "Conversion Constructor for " << this->getInput() << std::endl;
	this->convertInput();
	this->printOutput();
}

Conversion::Conversion(const Conversion &src)
{
	std::cout << "Conversion Copy Constructor called" << std::endl;
	*this = src;
}

// Deconstructors
Conversion::~Conversion()
{
	std::cout << "Conversion Deconstructor called" << std::endl;
}

// Overloaded Operators
Conversion &Conversion::operator=(const Conversion &src)
{
	std::cout << "Conversion Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	/*CODE*/
	return *this;
}

// Private Methods
int	Conversion::checkInput()
{
	if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 ||
		this->getInput().compare("-inf") == 0 || this->getInput().compare("+inff") == 0 ||
		this->getInput().compare("-inff") == 0)
	{
		return (NAN_INF);
	}
	else if (this->getInput().length() == 1 &&
		(this->getInput()[0] == '+' || this->getInput()[0] == '-' ||
		this->getInput()[0] == 'f' || this->getInput()[0] == '.') )
	{
		return (CHAR);
	}
	else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
		return (DOUBLE);
	else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().rbegin()[0] != 'f')
			return (IMPOSSIBLE);
		else
			return (FLOAT);
	}
	else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) ||
		(this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
	{
		return (CHAR);
	}
	else
		return (ERROR);
}

void Conversion::fromChar(void)
{
	this->_char = static_cast<unsigned char>(this->getInput()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}
void Conversion::fromInt(void)
{
	this->_int = static_cast<int>(this->getDouble());
	this->_char = static_cast<unsigned char>(this->getInt());
	this->_float = static_cast<float>(this->getDouble());
}
void Conversion::fromFloat(void)
{
	this->_float = static_cast<float>(this->getDouble());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
}
void Conversion::fromDouble(void)
{
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}

void	Conversion::convertInput(void)
{
	void (Conversion::*functionPTRS[])(void) = {&Conversion::fromChar, &Conversion::fromInt, &Conversion::fromFloat, &Conversion::fromDouble};
	int types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->_type = checkInput();

	if (this->getType() == NAN_INF || this->getType() == IMPOSSIBLE)
		return ;
	int i;
	for (i = 0; i < 3; i++)
	{
		if (this->getType() == types[i])
		{
			(this->*functionPTRS[i])();
			break ;
		}
	}
	if (i == 4)
		throw Conversion::ImpossibleException();
}

void	Conversion::printOutput(void)const
{
	if (this->getChar() < 32 || this->getChar() > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << this->getChar() << std::endl;
	std::cout << "int: " << this->getInt() << std::endl;
	std::cout << "float: " << this->getFloat() << "f" << std::endl;
	std::cout << "double: " << this->getDouble() << std::endl;
}
// Exceptions
const char *Conversion::ImpossibleException::what(void) const throw()
{
	return ("Impossible to print");
};

// const char *Form::GradeTooHighException::what(void) const throw()
// {
// 	return ("Grade too high");
// };

// Getter
std::string	Conversion::getInput(void)const
{
	return (this->_input);
}

int	Conversion::getType(void)const
{
	return (this->_type);
}

char	Conversion::getChar(void)const
{
	return (this->_char);
}

int	Conversion::getInt(void)const
{
	return (this->_int);
}

float	Conversion::getFloat(void)const
{
	return (this->_float);
}

double Conversion::getDouble(void)const
{
	return (this->_double);
}

// Setter

