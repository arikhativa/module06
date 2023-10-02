/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:56:15 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 12:43:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

std::string ScalarConverter::_str = "";
int ScalarConverter::_dots = 0;
t_type ScalarConverter::_type = ERROR;

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;

bool ScalarConverter::_int_overflow = false;
bool ScalarConverter::_float_overflow = false;
bool ScalarConverter::_double_overflow = false;
bool ScalarConverter::_no_decimal = false;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
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

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    (void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::convert(const char *arg)
{
    _str = arg;
    _dots = _countDots(_str);
    _type = ERROR;
    _int_overflow = false;
    _float_overflow = false;
    _double_overflow = false;
    _no_decimal = false;
    try
    {
        _validateInput();
        _initType();
        _setLimits();
        _convertValue();
        _printValues();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int ScalarConverter::_countDots(std::string str)
{
    int dots = 0;

    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it == '.')
            dots++;
    }
    return dots;
}

void ScalarConverter::_validateInput(void)
{
    if (_str.empty())
        throw std::invalid_argument("Empty argument");

    if (1 < _dots)
        throw std::invalid_argument("Too many dots");
}

void ScalarConverter::_initType(void)
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
        throw std::invalid_argument("Invalid argument: failed to detect type");
}

void ScalarConverter::_setLimits(void)
{
    double value = strtod(_str.c_str(), NULL);

    if (errno == ERANGE)
    {
        _int_overflow = true;
        _float_overflow = true;
        _double_overflow = true;
        return;
    }
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        _int_overflow = true;
    if (value < static_cast<double>(-FLT_MAX) || value > static_cast<double>(FLT_MAX))
        _float_overflow = true;
}

/*
** ------------------------------ PRINT METHODS --------------------------------
*/

void ScalarConverter::_printValues(void)
{
    _printChar();
    _printInt();
    _printFloat();
    _printDouble();
}

void ScalarConverter::_printChar(void)
{
    if (_type == PSEUDO_LITERALS)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (!std::isprint(_char))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << _char << "'" << std::endl;
}

void ScalarConverter::_printInt(void)
{
    if (_type == PSEUDO_LITERALS)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    if (_int_overflow)
    {
        std::cout << "int: overflow" << std::endl;
        return;
    }
    std::cout << "int: " << _int << std::endl;
}

void ScalarConverter::_printFloat(void)
{
    if (_float_overflow && _type != PSEUDO_LITERALS)
    {
        std::cout << "float: overflow" << std::endl;
        return;
    }
    if (_no_decimal)
    {
        std::cout << "float: " << _float << ".0f" << std::endl;
    }
    else
        std::cout << "float: " << _float << "f" << std::endl;
}

void ScalarConverter::_printDouble(void)
{
    if (_no_decimal)
    {
        std::cout << "double: " << _double << ".0" << std::endl;
    }
    else
        std::cout << "double: " << _double << std::endl;
}

/*
** ------------------------------ CONVERT METHODS ------------------------------
*/

void ScalarConverter::_convertValue(void)
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

void ScalarConverter::_convertChar(void)
{
    _char = _str[0];
    _int = static_cast<int>(_char);
    _float = static_cast<float>(_char);
    _double = static_cast<double>(_char);
    _no_decimal = true;
}

void ScalarConverter::_convertInt(void)
{
    if (_int_overflow)
    {
        throw std::overflow_error("Input is invalid integer: Overflow error");
    }
    _int = std::atoi(_str.c_str());
    _char = static_cast<char>(_int);
    _float = static_cast<float>(_int);
    _double = static_cast<double>(_int);
    _no_decimal = true;
}

bool ScalarConverter::_isWholeNumber(void)
{
    std::size_t i = _str.find('.');

    if (i == std::string::npos)
        return true;
    ++i;
    while (_str[i])
    {
        if (_str[i] != '0' && _str[i] != 'f')
            return false;
        ++i;
    }
    return true;
}

void ScalarConverter::_convertFloat(void)
{
    double d = std::atof(_str.c_str());

    if (_float_overflow)
    {
        throw std::overflow_error("Input is invalid float: Overflow error");
    }
    _float = static_cast<float>(d);
    _char = static_cast<char>(_float);
    _int = static_cast<int>(_float);
    _double = static_cast<double>(_float);
    if (_isWholeNumber())
        _no_decimal = true;
}

void ScalarConverter::_convertDouble(void)
{
    if (_double_overflow)
    {
        throw std::overflow_error("Input is invalid double: Overflow error");
    }
    _double = std::strtod(_str.c_str(), NULL);
    _char = static_cast<char>(_double);
    _int = static_cast<int>(_double);
    _float = static_cast<float>(_double);
    if (_isWholeNumber())
        _no_decimal = true;
}

void ScalarConverter::_convertPseudoLiterals(void)
{
    _char = 0;
    _int = 0;
    _float = _getFloatPseudoLiterals();
    _double = _getDoublePseudoLiterals();
}

/*
** -------------------------------- IS METHODS ---------------------------------
*/

bool ScalarConverter::_isChar(void)
{
    if (_str.length() == 1 && !std::isdigit(_str[0]))
    {
        if (!std::isprint(_str[0]))
            throw std::invalid_argument("Char is not printable");
        return true;
    }
    return false;
}

bool ScalarConverter::_isInt(void)
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

bool ScalarConverter::_isFloat(void)
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

bool ScalarConverter::_isDouble(void)
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

bool ScalarConverter::_isInfi(void)
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

float ScalarConverter::_getFloatPseudoLiterals(void)
{
    if (_str == "+inff" || _str == "+inf")
        return std::numeric_limits<float>::infinity();
    else if (_str == "-inff" || _str == "-inf")
        return -std::numeric_limits<float>::infinity();
    return std::numeric_limits<float>::quiet_NaN();
}

double ScalarConverter::_getDoublePseudoLiterals(void)
{
    if (_str == "+inff" || _str == "+inf")
        return std::numeric_limits<double>::infinity();
    else if (_str == "-inff" || _str == "-inf")
        return -std::numeric_limits<double>::infinity();
    return std::numeric_limits<double>::quiet_NaN();
}

/* ************************************************************************** */
