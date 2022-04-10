/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:02:44 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/10 15:45:37 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructors
Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = src;
}

// Deconstructors
Serializer::~Serializer()
{
	std::cout << "Serializer Deconstructor called" << std::endl;
}

// Overloaded Operators
Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	/*CODE*/
	return *this;
}

// Public Methods
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::unserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
// Getter

// Setter

// Ostream overload
// std::ostream	&operator<<(std::ostream &o, Data *a)
// {
// 	o <<
// 	"\tName: " << a->name <<
// 	"\n\tage: " << a->age <<
// 	std::endl;
// 	return (o);
// }
