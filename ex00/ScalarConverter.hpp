/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:56:13 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/18 10:37:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <limits>

typedef enum	e_type
{
	ERROR = -1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_LITERALS
}				t_type;

class ScalarConverter
{

	public:
		explicit	ScalarConverter(const char *arg);
		~ScalarConverter();

	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		ScalarConverter &		operator=( ScalarConverter const & rhs );

		std::string			_str;
		const int			_dots;
		t_type				_type;

		char				_char;
		int					_int;
		float				_float;
		double				_double;

		void		_validateInput(void);
		void		_initType(void);

	// convert()
		void	_convert(void);
		void	_convertChar(void);
		void	_convertInt(void);
		void	_convertFloat(void);
		void	_convertDouble(void);
		void	_convertPseudoLiterals(void);

	// is()
		bool	_isInfi(void);
		bool	_isChar(void);
		bool	_isInt(void);
		bool	_isFloat(void);
		bool	_isDouble(void);

	// util
		float	_getFloatPseudoLiterals(void) const;
		double	_getDoublePseudoLiterals(void) const;

	// print()
		void	_printValues(void) const;
		void	_printChar(void) const;
		void	_printInt(void) const;
		void	_printFloat(void) const;
		void	_printDouble(void) const;
		void	_printPseudoLiterals(void) const;

};

#endif /* ************************************************* SCALARCONVERTER_H */