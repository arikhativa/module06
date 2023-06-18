/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:07:45 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/18 16:09:42 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	public:
		Data();
		Data( Data const & src );
		~Data();

		Data &		operator=( Data const & rhs );

		int	getValue(void) const;

	private:
		int	_i;

};

std::ostream &			operator<<( std::ostream & o, Data const & i );

#endif /* ************************************************************ DATA_H */