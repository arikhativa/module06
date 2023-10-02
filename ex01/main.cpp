/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 14:42:40 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *d1 = new Data(42, 'a', 5.5);
    Data *ptr;

    uintptr_t raw = Serializer::serialize(d1);
    ptr = Serializer::deserialize(raw);

    std::cout << "original:\t" << d1 << std::endl;
    std::cout << "ptr:\t\t" << ptr << std::endl;

    std::cout << "original:\t" << *d1 << std::endl;
    std::cout << "ptr:\t\t" << *ptr << std::endl;

    delete d1;

    return 0;
}
