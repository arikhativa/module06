/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/18 16:13:38 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	Data d;

	std::cout << d << std::endl;
	return 0;
}
