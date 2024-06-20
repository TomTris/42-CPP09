/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:17:41 by qdo               #+#    #+#             */
/*   Updated: 2024/06/20 16:58:35 by qdo              ###   ########.fr       */
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
	std::vector<int>  			check;
	std::vector<int>::iterator  ite;
	std::vector<int>::iterator  ite2;

	while (av[++i])
	{
		if (!invalid_number(static_cast<std::string>(av[i])))
			return (false);
		check.push_back(std::atoi(av[i]));
	}
	ite = check.begin();
	while (ite != check.end() - 1)
	{
		ite2 = ite + 1;
		while (ite2 != check.end())
		{
			if (*ite2 == *ite)
			{
				eprint("Duplicate number");
				return false;
			}
			ite2++;
		}
		ite++;
	}
	return (true);
}
