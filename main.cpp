#include "PmergeMe.hpp"

void	check_sorted(std::vector<std::pair<int, int> >&uper)
{
	std::vector<std::pair<int, int> >::iterator ite = uper.begin() - 1;
	while (++ite != uper.end() - 1)
	{
		if (ite->first > (ite + 1)->first)
		{
			std::cout << "Not sorted" << std::endl;
			return ;
		}
	}
}

// bool sortByFirst(const std::pair<int, int>& left, const std::pair<int, int>& right) {
//     return left.first < right.first;
// }
// std::sort(uper.begin(), uper.end(), sortByFirst);

unsigned int	y_nb_gen(int check, std::vector<std::pair<int, int> > &lower)
{
	static unsigned int	ret = 0;
	static unsigned int	size = 0;
	static unsigned int a = 0;
	static unsigned int b = 0;
	
	if (check == 1)
	{

	}
}

void	minsert(std::vector<std::pair<int, int> > &uper, std::vector<std::pair<int, int> > &lower)
{
	int	cnt = 0;
	(void) lower;

	uper.insert(uper.begin(), *lower.begin());
	
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
	minsert(uper, lower);
	mVec = uper;
}


int	main(int ac, char **av)
{
	std::vector<int> mVec_o;
	if (ac <= 2)
		return (0);
	if (av_check(av) == false)
		return (1);
	generate(mVec_o, av);

	std::vector<std::pair<int, int> > mVec;
	for (unsigned int i = 0; i < mVec_o.size(); i++)
	{
		mVec.push_back(std::make_pair(mVec_o[i], i));
	}
	mmerge(mVec);
	std::cout << "mVec.size() = " << mVec.size() << std::endl;
	mVecPrint(mVec);
}
