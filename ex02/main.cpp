/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/03 14:45:18 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void)
{
    std::srand(std::time(NULL));
    int random_variable = std::rand();
    if (random_variable % 3 == 0)
    {
        std::cout << "created A" << std::endl;

        return (new A);
    }
    else if (random_variable % 3 == 1)
    {
        std::cout << "created B" << std::endl;

        return (new B);
    }
    else
    {
        std::cout << "created C" << std::endl;
        return (new C);
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &tmp = dynamic_cast<A &>(p);
        (void)tmp;
        std::cout << "A" << std::endl;
        return;
    }
    catch (...)
    {
    }
    try
    {
        B &tmp = dynamic_cast<B &>(p);
        (void)tmp;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
    {
    }
    std::cout << "C" << std::endl;
}

int main()
{
    Base *base = generate();

    identify(base);
    identify(*base);

    delete base;

    return 0;
}
