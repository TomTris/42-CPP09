/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:40:43 by qdo               #+#    #+#             */
/*   Updated: 2024/06/20 16:41:41 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int	jacob_gen(int check, std::vector<std::pair<int, int> > &lower)
{
	static unsigned int	ret = 0;
	static unsigned int a = 2;
	static unsigned int b = 2;
	unsigned int		temp;
	
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
	if (ret > lower.size() - 1)
		ret = lower.size() - 1;
	return (ret);
}

void	binary_sort(std::vector<std::pair<int, int> >&uper, std::pair<int, int> &lower,
		unsigned int start, unsigned int end)
{
	unsigned int	middle = (end + start) / 2;

	if (start == middle)
	{
		if (lower.first < uper[middle].first)
			uper.insert(uper.begin() + middle, lower);
		else
			uper.insert(uper.begin() + middle + 1, lower);
		return ;
	}
	if (lower.first < uper[middle].first)
		binary_sort(uper, lower, start, middle);
	else
		binary_sort(uper, lower, middle + 1, end);
}

void	minsert(std::vector<std::pair<int, int> > &uper, std::vector<std::pair<int, int> > &lower)
{
	(void) lower;
	unsigned int low_i;
	bool odd_nbr = false;

	if (lower.size() > uper.size())
		odd_nbr = true;
	uper.insert(uper.begin(), *lower.begin());
	lower.erase(lower.begin());
	low_i = jacob_gen(1, lower);
	while (lower.size() >= 2)
	{
		binary_sort(uper, lower[low_i], 0, uper.size() - 1);
		lower.erase(lower.begin() + low_i);
		low_i = jacob_gen(0, lower);
	}
	if (odd_nbr == true && lower[0].first > uper[uper.size() - 1].first)
		uper.push_back(lower[0]);
	else
		binary_sort(uper, lower[0], 0, uper.size() - 1);
}

void	change_pair_lower(std::vector<std::pair<int, int> > &uper, std::vector<std::pair <int, int> > &lower)
{
	std::vector<std::pair<int, int> > lower2;
	unsigned int cnt;
	unsigned int cnt2;
	unsigned int uper_o_size = uper.size();

	lower2 = lower;
	lower.clear();
	cnt = 0;
	while (cnt < uper_o_size)
	{
		cnt2 = 0;
		while (1)
		{
			if (lower2[cnt2].second == uper[cnt].second)
			{
				lower.push_back(lower2[cnt2]);
				lower2.erase(lower2.begin() + cnt2);
				break ;
			}
			cnt2++;
		}
		cnt++;
	}
	if (lower2.size() > 0)
		lower.push_back(lower2[lower2.size() - 1]);
}

void	set_pair_uper(std::vector<std::pair<int, int> > & mVec, std::vector<std::pair<int, int> > & uper)
{
	unsigned int	i = 0;
	unsigned int	uper_size = uper.size();
	unsigned int	j;
	
	while (i < uper_size)
	{
		j = 0;
		while (1)
		{
			if (uper[i].first == mVec[j].first)
			{
				uper[i].second = mVec[j].second;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	mmerge(std::vector<std::pair<int, int> > & mVec)
{
	if (mVec.size() == 1)
		return ;
	if (mVec.size() == 2)
	{
		if (mVec[0].first > mVec[1].first)
			std::swap(mVec[0], mVec[1]);
		return ;
	}
	unsigned int	cnt = 0;
	std::vector<std::pair<int, int> > uper;
	std::vector<std::pair<int, int> > lower;
	while (cnt * 2 + 2 <= mVec.size())
	{
		if (mVec[cnt * 2] > mVec[cnt * 2 + 1])
		{
			uper.push_back(std::make_pair(mVec[cnt * 2].first, cnt));
			lower.push_back(std::make_pair(mVec[cnt * 2 + 1].first, cnt));
		}
		else
		{
			lower.push_back(std::make_pair(mVec[cnt * 2].first, cnt));
			uper.push_back(std::make_pair(mVec[cnt * 2 + 1].first, cnt));
		}
		cnt += 1;
	}
	if (mVec.size() == cnt * 2 + 1)
		lower.push_back(std::make_pair(mVec[cnt * 2].first, cnt));
	mmerge(uper);
	change_pair_lower(uper, lower);
	minsert(uper, lower);
	set_pair_uper(mVec, uper);
	mVec = uper;
}

void generate(std::vector<int> & mVec, char **av)
{
	int i = 0;
	while (av[++i])
		mVec.push_back(std::atoi(av[i]));
	return ;
}

void mVecPrint(std::vector<std::pair<int, int> > mVec)
{
	std::vector<std::pair<int, int> >::iterator ite = mVec.begin() - 1;
	int	i = 0;
	while (++ite != mVec.end())
		std::cout << mVec.at(i++).first << " " << std::ends;
	std::cout << std::endl;
}
