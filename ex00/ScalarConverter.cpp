/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:56:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/18 13:05:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
** ----------------------------- STATIC FUNCTION -------------------------------
*/

static int	countDots(std::string str)
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
	:	_str(arg),
		_dots(countDots(_str)),
		_type(ERROR),
		_int_overflow(false),
		_float_overflow(false),
		_double_overflow(false)
{
	try
	{
		_validateInput();
		_initType();
		_setLimits();
		_convert();
		_printValues();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

ScalarConverter::ScalarConverter()
	:	_str(""),
		_dots(0),
		_type(ERROR),
		_int_overflow(false),
		_float_overflow(false),
		_double_overflow(false)
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
	:	_str(""),
		_dots(0),
		_type(ERROR),
		_int_overflow(false),
		_float_overflow(false),
		_double_overflow(false)
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

void	ScalarConverter::_validateInput(void)
{
	if (_str.empty())
		throw std::invalid_argument("Empty argument");

	if (1 < _dots)
		throw std::invalid_argument("Too many dots");
}

void	ScalarConverter::_initType(void)
{
	if (_isInfi())
		_type = PSEUDO_LITERALS;
	else if (_isChar())
		_type = CHAR;
	else if (_isInt())
		_type = INT;
	else if (_isFloat())
		_type = FLOAT;
	else if (_isDouble())
		_type = DOUBLE;
	if (_type == ERROR)
		throw std::invalid_argument("Invalid argument");
}


void		ScalarConverter::_setLimits(void)
{
	double value = strtod(_str.c_str(), NULL);

	if (errno == ERANGE)
	{
		_int_overflow = true;
		_float_overflow = true;
		_double_overflow = true;
	}
	if (value < INT_MIN || value > INT_MAX)
		_int_overflow = true;
	if (value < -FLT_MAX || value > FLT_MAX)
		_float_overflow = true;
} 

/*
** ------------------------------ PRINT METHODS --------------------------------
*/

void	ScalarConverter::_printValues(void) const
{
	_printChar();
	_printInt();
	_printFloat();
	_printDouble();
}

void	ScalarConverter::_printChar(void) const
{
	if (_type == PSEUDO_LITERALS)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(_char))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _char << "'" << std::endl;
}

void	ScalarConverter::_printInt(void) const
{
	if (_type == PSEUDO_LITERALS)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (_int_overflow)
	{
		std::cout << "int: overflow" << std::endl;
		return ;
	}
	std::cout << "int: " << _int << std::endl;
}

void	ScalarConverter::_printFloat(void) const
{
	if (_float_overflow && _type != PSEUDO_LITERALS)
	{
		std::cout << "float: overflow" << std::endl;
		return ;
	}
	std::cout << "float: " << std::setprecision(1) << std::fixed << _float << "f" <<  std::endl;
}

void	ScalarConverter::_printDouble(void) const
{
	std::cout << "double: " << std::setprecision(1) << std::fixed << _double << std::endl;
}

/*
** ------------------------------ CONVERT METHODS ------------------------------
*/

void	ScalarConverter::_convert(void)
{
	switch (_type)
	{
		case CHAR:
			_convertChar();
			break;
		case INT:
			_convertInt();
			break;
		case FLOAT:
			_convertFloat();
			break;
		case DOUBLE:
			_convertDouble();
			break;
		case PSEUDO_LITERALS:
			_convertPseudoLiterals();
			break;
		default:
			break;
	}
}

void	ScalarConverter::_convertChar(void)
{
	_char = _str[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	ScalarConverter::_convertInt(void)
{
	if (_int_overflow)
	{
		throw std::overflow_error("Input is invalid integer: Overflow error");
	}
	_int = std::atoi(_str.c_str());
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void	ScalarConverter::_convertFloat(void)
{
	double	d = std::atof(_str.c_str());

	if (_float_overflow)
	{
		throw std::overflow_error("Input is invalid float: Overflow error");
	}
	_float = static_cast<float>(d);
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
}

void	ScalarConverter::_convertDouble(void)
{
	if (_double_overflow)
	{
		throw std::overflow_error("Input is invalid double: Overflow error");
	}
	_double = std::strtod(_str.c_str(), NULL);
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);
}

void	ScalarConverter::_convertPseudoLiterals(void)
{
	_char = 0;
	_int = 0;
	_float = _getFloatPseudoLiterals();
	_double = _getDoublePseudoLiterals();
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

bool	ScalarConverter::_isInt(void)
{
	if (_dots)
		return false;

	std::string::const_iterator it = _str.begin();

	if (*it == '+' || *it == '-')
		it++;
	while (it != _str.end())
	{
		if (!std::isdigit(*it))
			return false;
		++it;
	}
	return true;
}

bool	ScalarConverter::_isFloat(void)
{
	if (!_dots)
		return false;

	std::string::const_iterator it = _str.begin();

	if (_str.length() == 2)
	{
		if (*it == '.' && *(it + 1) == 'f')
			throw std::invalid_argument("Invalid Float: no digits");
	}
	if (*it == '+' || *it == '-')
		it++;
	while (it != _str.end())
	{
		if (!std::isdigit(*it) && *it != '.')
		{
			if (*it != 'f')
				throw std::invalid_argument("Invalid Float: bad char");
			if (it + 1 != _str.end())
				throw std::invalid_argument("Invalid Float: char after 'f'");
		}
		++it;
	}
	return _str.find('f') != std::string::npos;
}

bool	ScalarConverter::_isDouble(void)
{
	if (!_dots)
		return false;

	std::string::const_iterator it = _str.begin();

	if (*it == '+' || *it == '-')
		it++;
	while (it != _str.end())
	{
		if (!std::isdigit(*it) && *it != '.')
			throw std::invalid_argument("Invalid Double: bad char");
		++it;
	}
	return true;
}

bool	ScalarConverter::_isInfi(void)
{
	if (_dots)
		return false;
	if (_str == "-inff" || _str == "+inff" || _str == "nanf")
		return true;
	if (_str == "-inf" || _str == "+inf" || _str == "nan")
		return true;
	return false;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

float	ScalarConverter::_getFloatPseudoLiterals(void) const
{
	if (_str == "+inff" || _str == "+inf")
		return std::numeric_limits<float>::infinity();
	else if (_str == "-inff" || _str == "-inf")
		return -std::numeric_limits<float>::infinity();
	return std::numeric_limits<float>::quiet_NaN();
}

double	ScalarConverter::_getDoublePseudoLiterals(void) const
{
	if (_str == "+inff" || _str == "+inf")
		return std::numeric_limits<double>::infinity();
	else if (_str == "-inff" || _str == "-inf")
		return -std::numeric_limits<double>::infinity();
	return std::numeric_limits<double>::quiet_NaN();
}

/* ************************************************************************** */