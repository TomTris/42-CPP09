/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:59:17 by qdo               #+#    #+#             */
/*   Updated: 2024/06/20 07:58:41 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>  // for std::swap_ranges
unsigned int	jacob_gen(int check, unsigned int & size)
{
	static unsigned int	ret = 0;
	static unsigned int a = 2;
	static unsigned int b = 2;
	unsigned int        temp;

    if (size == 0)
		return (std::cout << "size = 0" << std::endl, 0);
	if (check == 1)
	{
		a = 2;
		b = 2;
		ret = 2;
	}
	if (ret != 0)
		return (--ret);
	temp = a;
	a = b;
	b = 2 * temp + b;
	ret = a - 1;
	if (ret > size - 1)
		ret = size - 1;
	return (ret);
}

int main() {
	std::vector<int> vec;
    unsigned int size = 2;
    unsigned int a = jacob_gen(1, size);
    while (size != 2)
    {
        std::cout << a << std::endl;
        a = jacob_gen(0, size);
        size--;
    }
    std::cout << a << std::endl;
    a = jacob_gen(0, size);
    return 0;
}