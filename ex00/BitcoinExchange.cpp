/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:18:58 by qdo               #+#    #+#             */
/*   Updated: 2024/06/18 17:43:04 by qdo              ###   ########.fr       */
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
