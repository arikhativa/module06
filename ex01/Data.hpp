/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:07:45 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 12:43:17 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
  public:
    Data(int i, char c, float f);
    Data(Data const &src);
    ~Data();

    Data &operator=(Data const &rhs);

    int getInt(void) const;
    char getChar(void) const;
    float getFloat(void) const;

  private:
    int _i;
    char _char;
    float _float;
};

std::ostream &operator<<(std::ostream &o, Data const &i);

#endif /* ************************************************************ DATA_H */
