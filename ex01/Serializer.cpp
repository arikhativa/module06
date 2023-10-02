/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:13:28 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 14:40:14 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
    (void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &Serializer::operator=(Serializer const &rhs)
{
    (void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

/* ************************************************************************** */
