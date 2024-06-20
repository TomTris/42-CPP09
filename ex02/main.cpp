#include <algorithm>
#include "PmergeMe.hpp"

void	mswap(std::vector<int> & mVec, unsigned int start, unsigned int size)
{
	unsigned int	cnt = 0;
	
	if (mVec[start + size / 2 - 1] > mVec[start + size - 1])
	{
		while (cnt < size / 2)
		{
			std::swap(mVec[start + cnt], mVec[start + size / 2 + cnt]);
			cnt++;
		}
	}
}

  void	m_erase_insert(std::vector<int> & mVec, unsigned int start, unsigned int size, unsigned int new_index)
{
	std::vector<int> temp;
	std::copy(mVec.begin() + start, mVec.begin() + start + size, std::back_inserter(temp));
	if (start > new_index)
	{
		mVec.erase(mVec.begin() + start, mVec.begin() + start + size);
		mVec.insert(mVec.begin() + new_index, temp.begin(), temp.begin());	
	}
	else
	{
		mVec.insert(mVec.begin() + new_index, temp.begin(), temp.begin());
		mVec.erase(mVec.begin() + start, mVec.begin() + start + size);
	}
}

void	mmerge(std::vector<int> & mVec, unsigned int size)
{
	unsigned int	cnt;

	if (size > mVec.size())
		return ;
	cnt = 0;
	while (mVec.size() >= (cnt + 1) * size)
	{
		mswap(mVec, (cnt * size), size);
		cnt++;
	}
	mmerge(mVec, size * 2);
}

void	minsert(std::vector<int> mVec, int size)
{
	int	cnt = 0;
	
	while ( )
}

int	main(int ac, char **av)
{
	std::vector<int> mVec;
	if (ac <= 2)
		return (0);
	if (av_check(av) == false)
		return (1);
	generate(mVec, av);
	mmerge(mVec, 2);
	// int	cnt = 2;
	// while ((cnt * 2) <= mVec.size())
	// 	cnt *= 2;
	// minsert(mVec, cnt / 2);
	mVecPrint(mVec);
}
