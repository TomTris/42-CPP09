/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:17:41 by qdo               #+#    #+#             */
/*   Updated: 2024/06/20 16:39:53 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int oprint(std::string str)
{
	std::cout << str << std::endl;
	return (0);
}
int eprint(std::string str)
{
	std::cout << "Error: " << str << std::endl;
	return (1);
}

bool invalid_number(std::string str)
{
	if (str.size() == 0)
		return (eprint("Size = 0"), false);
	std::string::iterator ite = str.begin();
	if (*ite == '+' || *ite == '-')
		ite++;
	ite--;
	while (++ite != str.end())
	{
		if (!std::isdigit(*ite))
			return (eprint("Invalid character"), false);
	}
	return (true);
}

bool av_check(char **av)
{
	int	i = 0;
	while (av[++i])
		if (!invalid_number(static_cast<std::string>(av[i])))
			return (false);
	return (true);
}
