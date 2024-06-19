/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:18:58 by qdo               #+#    #+#             */
/*   Updated: 2024/06/19 09:26:05 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *StopF::what() const throw()
{
	return ("Programm stops");
}

std::string actualString(std::string const & str_o)
{
    std::string::iterator   iter;
    std::string    str = (std::string) str_o;
    std::string    ret = "";
    bool                    pre_white_space = false;

    iter = str.begin();
    while (iter != str.end() && (*iter == ' ' || *iter == '\n'
        || *iter == '\t' || *iter == '\r' || *iter == '\v' || *iter == '\f'))
        iter++;
    while (iter != str.end())
    {
        if (*iter == ' ' || *iter == '\n' || *iter == '\t'
            || *iter == '\r' || *iter == '\v' || *iter == '\f')
            pre_white_space = true;
        else
        {
            if (pre_white_space == true)
            {
                pre_white_space = false;
                ret.push_back(' ');
            }
            ret.push_back(*iter);
        }
        iter += 1;
    }
    return ret;
}

int	mprint_invalid_amount(void)
{
	std::cout << "Error: Invalid amount of bitcoin" << std::endl;
	return (1);
}

int mprint(std::string str)
{
	std::cout << str << std::endl;
	return (0);
}

int	strToInt(std::string str)
{
	std::stringstream ss;
	int	ret;
	ss << str;
	ss >> ret;
	return ret;
}

float	strToFloat(std::string str)
{
	std::stringstream ss;
	float	ret;
	ss << str;
	ss >> ret;
	return ret;
}
