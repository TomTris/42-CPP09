/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:45:45 by qdo               #+#    #+#             */
/*   Updated: 2024/06/19 21:55:47 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility> 

//A.cpp
int				 oprint(std::string str);
bool			 invalid_number(std::string str);
bool			 av_check(char **av);
void			 generate(std::vector<int> & mVec, char **av);
void			 mVecPrint(std::vector<std::pair<int, int> > mVec);
#endif