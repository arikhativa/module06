/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/18 13:02:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "usage: ./convert [string]" << std::endl;
		return 0;
	}
	ScalarConverter s(av[1]);
	return 0;
}
