/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:59:17 by qdo               #+#    #+#             */
/*   Updated: 2024/06/19 15:01:28 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>  // for std::swap_ranges

int main() {
	std::vector<int> vec;

	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
    // Print original vector
    std::cout << "Original vector: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Swap elements in positions 0-4 with elements in positions 5-9
    std::swap_ranges(vec.begin(), vec.begin() + 5, vec.begin() + 5);

    // Print modified vector
    std::cout << "Modified vector: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}