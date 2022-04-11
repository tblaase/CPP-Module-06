/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:37:12 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/11 17:38:29 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

// Constructors
Conversion::Conversion()
{
	std::cout << "Conversion Default Constructor called" << std::endl;
}

Conversion::Conversion(const std::string input): _input(input)
{
	std::cout << "Conversion Constructor for " << this->getInput() << std::endl;
	this->_double = atof(this->getInput().c_str());
	this->convertInput();
	this->printOutput();
}

Conversion::Conversion(const Conversion &src): _input(src.getInput())
{
	std::cout << "Conversion Copy Constructor called" << std::endl;
	*this = src;
	this->printOutput();
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

	this->_type = src.getType();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
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
		this->getInput()[0] == 'f' || this->getInput()[0] == '.'))
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
		else if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f"))
			return (ERROR);
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
	for (i = 0; i < 4; i++)
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
	// display char
	if (this->getType() != IMPOSSIBLE && this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() && this->getDouble() <= std::numeric_limits<int>::max())
	{
		if (isprint(this->getChar())/*this->getChar() >= 32 && this->getChar() <= 126*/)
			std::cout << "char: '" << this->getChar() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// display int
	if (this->getType() != IMPOSSIBLE && this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() && this->getDouble() <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << this->getInt() << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	// display float
	if (this->getType() != NAN_INF && this->getType() != IMPOSSIBLE)
	{
		std::cout << "float: " << this->getFloat();
		if (this->getFloat() - this->getInt() == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
	{
		if (this->getType() == IMPOSSIBLE)
			std::cout << "float: impossible" << std::endl;
		else if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}

	// display double
	if (this->getType() != NAN_INF && this->getType() != IMPOSSIBLE)
	{
		std::cout << "double: " << this->getDouble();
		if (this->getDouble() < std::numeric_limits<int>::min() || this->getDouble() > std::numeric_limits<int>::max() ||
			this->getDouble() - this->getInt() == 0)
		{
			std::cout << ".0" << std::endl;
		}
		else
			std::cout << std::endl;
	}
	else
	{
		if (this->getType() == IMPOSSIBLE)
			std::cout << "double: impossible" << std::endl;
		else if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

// Exceptions
const char *Conversion::ImpossibleException::what(void) const throw()
{
	return ("Error: Impossible to print or input not convertable");
};

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

