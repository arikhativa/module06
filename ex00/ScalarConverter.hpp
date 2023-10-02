/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:56:13 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 14:26:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cerrno>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter
{
  public:
    static void convert(const char *arg);

  private:
    enum type
    {
        ERROR = -1,
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        PSEUDO_LITERALS
    };

    ~ScalarConverter();
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &rhs);

    static std::string _str;
    static int _dots;
    static type _type;

    static char _char;
    static int _int;
    static float _float;
    static double _double;

    static bool _int_overflow;
    static bool _float_overflow;
    static bool _double_overflow;
    static bool _no_decimal;

    static void _validateInput(void);
    static void _initType(void);
    static void _setLimits(void);
    static int _countDots(std::string str);

    // convert()
    static void _convertValue(void);
    static void _convertChar(void);
    static void _convertInt(void);
    static void _convertFloat(void);
    static void _convertDouble(void);
    static void _convertPseudoLiterals(void);

    // is()
    static bool _isInfi(void);
    static bool _isChar(void);
    static bool _isInt(void);
    static bool _isFloat(void);
    static bool _isDouble(void);
    static bool _isWholeNumber(void);

    // util
    static float _getFloatPseudoLiterals(void);
    static double _getDoublePseudoLiterals(void);

    // print()
    static void _printValues(void);
    static void _printChar(void);
    static void _printInt(void);
    static void _printFloat(void);
    static void _printDouble(void);
    static void _printPseudoLiterals(void);
};

#endif /* ************************************************* SCALARCONVERTER_H */
