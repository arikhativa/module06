/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:56:13 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/17 15:41:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

typedef enum	e_type
{
	ERROR = -1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
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

		void		_validateInput(void);
		void		_initType(void);

	// is()
		bool	_isChar(void);
		bool	_isNumber(void);
		bool	_isInt(void);
		bool	_isFloat(void);
		bool	_isDouble(void);

};

#endif /* ************************************************* SCALARCONVERTER_H */