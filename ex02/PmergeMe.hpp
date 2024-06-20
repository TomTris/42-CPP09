/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:45:45 by qdo               #+#    #+#             */
/*   Updated: 2024/06/20 16:49:03 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <deque> 

//A.cpp
int				 oprint(std::string str);
bool			 invalid_number(std::string str);
bool			 av_check(char **av);
void			 generate(std::vector<int> & mVec, char **av);
void			 mVecPrint(std::vector<std::pair<int, int> > mVec);


void			 mVecPrint(std::vector<std::pair<int, int> > mVec);
void			 generate(std::vector<int> & mVec, char **av);
void			mmerge(std::vector<std::pair<int, int> > & mVec);
void			set_pair_uper(std::vector<std::pair<int, int> > & mVec, std::vector<std::pair<int, int> > & uper);
void			change_pair_lower(std::vector<std::pair<int, int> > &uper, std::vector<std::pair <int, int> > &lower);
void			minsert(std::vector<std::pair<int, int> > &uper, std::vector<std::pair<int, int> > &lower);
void			binary_sort(std::vector<std::pair<int, int> >&uper, std::pair<int, int> &lower,
					unsigned int start, unsigned int end);
unsigned int	jacob_gen(int check, std::vector<std::pair<int, int> > &lower);

void			 dmVecPrint(std::deque<std::pair<int, int> > mVec);
void			 dgenerate(std::deque<int> & mVec, char **av);
void			dmmerge(std::deque<std::pair<int, int> > & mVec);
void			dset_pair_uper(std::deque<std::pair<int, int> > & mVec, std::deque<std::pair<int, int> > & uper);
void			dchange_pair_lower(std::deque<std::pair<int, int> > &uper, std::deque<std::pair <int, int> > &lower);
void			dminsert(std::deque<std::pair<int, int> > &uper, std::deque<std::pair<int, int> > &lower);
void			dbinary_sort(std::deque<std::pair<int, int> >&uper, std::pair<int, int> &lower,
					unsigned int start, unsigned int end);
unsigned int	djacob_gen(int check, std::deque<std::pair<int, int> > &lower);

#endif