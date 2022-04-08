/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:37:02 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/08 11:47:00 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <cctype>

#define NAN_INF 1
#define IMPOSSIBLE 2
#define ERROR 3
#define CHAR 4
#define INT 5
#define FLOAT 6
#define DOUBLE 7

// classes

class Conversion
{
	private:
		const std::string _input;
		int _type;
		char _char;
		int _int;
		float _float;
		double _double;

		// Constructor
		Conversion();
		// Methods
		int checkInput(void);
		void convertInput(void);

		void fromChar(void);
		void fromInt(void);
		void fromFloat(void);
		void fromDouble(void);

		void printOutput(void)const;

		// Getter
		std::string getInput(void)const;
		int getType(void)const;
		char getChar(void)const;
		int getInt(void)const;
		float getFloat(void)const;
		double getDouble(void)const;
		// Setter
	public:
	// Constructors
		Conversion(const std::string input);
		Conversion(const Conversion &src);

	// Deconstructors
		~Conversion();

	// Overloaded Operators
		Conversion &operator=(const Conversion &src);

	//Exceptions
	class ImpossibleException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// class GradeTooHighException : public std::exception
	// {
	// public:
	// 	virtual const char *what() const throw();
	// };

	// Public Methods
};