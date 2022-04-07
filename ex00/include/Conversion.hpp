/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:37:02 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/07 17:16:22 by tblaase          ###   ########.fr       */
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

// classes

class Conversion
{
	private:
		std::string _input;
		std::string _type;

		Conversion();
	public:
	// Constructors
		Conversion(const Conversion &src);

	// Deconstructors
		~Conversion();

	// Overloaded Operators
		Conversion &operator=(const Conversion &src);

	// //Exceptions
	// class ImpossibleException : public std::exception
	// {
	// public:
	// 	virtual const char *what() const throw();
	// };

	// class GradeTooHighException : public std::exception
	// {
	// public:
	// 	virtual const char *what() const throw();
	// };

	// Public Methods

	// Getter

	// Setter
		void setTypeFlag(void);
};