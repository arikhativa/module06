/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:08:36 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 14:40:09 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data(int i, char c, float f) : _i(i), _char(c), _float(f)
{
}

Data::Data(const Data &src)
{
    (void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &Data::operator=(Data const &rhs)
{
    (void)rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &o, Data const &i)
{
    o << "Data[" << i.getInt() << ", '" << i.getChar() << "', " << i.getFloat() << "]";
    return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Data::getInt(void) const
{
    return _i;
}

char Data::getChar(void) const
{
    return _char;
}

float Data::getFloat(void) const
{
    return _float;
}

/* ************************************************************************** */
