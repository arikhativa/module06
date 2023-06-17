/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:56:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/17 15:42:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	_countDots(std::string str)
{
	int dots = 0;

	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == '.')
			dots++;
	}
	return dots;
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter(const char *arg)
	: _str(arg), _dots(_countDots(_str)), _type(ERROR)
{
	try
	{
		_validateInput();
		_initType();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** ----------------------------- PRIVATE METHODS -------------------------------
*/

void	ScalarConverter::_validateInput(void)
{
	if (_str.empty())
		throw std::invalid_argument("Empty argument");

	if (1 < _dots)
		throw std::invalid_argument("Too many dots");
		
}

void	ScalarConverter::_initType(void)
{
	if (_isChar())
		_type = CHAR;
	if (!_isNumber())
		throw std::invalid_argument("Not a number");
	else if (_isInt())
		_type = INT;
	else if (_isFloat())
		_type = FLOAT;
	else if (_isDouble())
		_type = DOUBLE;
}


/*
** -------------------------------- IS METHODS ---------------------------------
*/

bool	ScalarConverter::_isChar(void)
{
	if (_str.length() == 1 && !std::isdigit(_str[0]))
	{
		if (!std::isprint(_str[0]))
			throw std::invalid_argument("Char is not printable");
		return true;
	}
	return false;
}

bool	ScalarConverter::_isNumber(void)
{
	std::string::const_iterator it = _str.begin();

	if (*it == '+' || *it == '-')
		it++;
	while (it != _str.end())
	{
		if (!std::isdigit(*it) && *it != '.')
			return false;
		++it;
	}
	return true;
}

bool	ScalarConverter::_isInt(void)
{
	if (_dots)
		return false;
	return true;
}

bool	ScalarConverter::_isFloat(void)
{

}

bool	ScalarConverter::_isDouble(void)
{

}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */