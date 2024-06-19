/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:19:08 by qdo               #+#    #+#             */
/*   Updated: 2024/06/19 08:48:04 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <map>
# include <fstream>
# include <exception>

class StopF : public std::exception {
	public:
		const char *what() const throw();
};

void							find_data(std::map<std::string, float> const & data,
									std::string const & date,
									float const bit_amount);
bool							is_valid_date(std::string const date);
float							calculate(float const amount, float const price);
std::map<std::string, float>	get_data(std::string const &file_name);
bool							valid_data(std::string const &actual);
std::string						actualString(std::string const & str_o);
std::map<std::string, float>	data_input(std::string const file_name);
int								mprint_invalid_amount(void);
#endif