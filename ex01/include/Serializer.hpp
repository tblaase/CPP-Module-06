/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:02:17 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/10 15:45:42 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

// classes

typedef struct Data
{
	std::string	name;
	size_t		age;
	Data		*next;
}				Data;

class Serializer
{
	private:
		// private Members
	public:
	// Constructors
		Serializer();
		Serializer(const Serializer &src);

	// Deconstructors
		~Serializer();

	// Overloaded Operators
		Serializer &operator=(const Serializer &src);

	// Public Methods
		uintptr_t serialize(Data *ptr);
		Data *unserialize(uintptr_t raw);
	// Getter

	// Setter

};

// Ostream overload
// std::ostream	&operator<<(std::ostream &o, Data *a);
