/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:37:12 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/07 16:37:17 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"


// Constructors
Conversion::Conversion()
{
	std::cout << "Conversion Default Constructor called" << std::endl;
	/*CODE*/
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
	/*CODE*/
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

// Public Methods

// Getter

// Setter

