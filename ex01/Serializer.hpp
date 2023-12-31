/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:06:48 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 14:40:15 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

#include "Data.hpp"

class Serializer
{
  public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

  private:
    Serializer();
    Serializer(Serializer const &src);
    ~Serializer();
    Serializer &operator=(Serializer const &rhs);
};

#endif /* ****************************************************** SERIALIZER_H */
