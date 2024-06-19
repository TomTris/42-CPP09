#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

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

void generate(std::vector<int> & mVec, char **av)
{
	int i = 0;
	while (av[++i])
		mVec.push_back(std::atoi(av[i]));
	return ;
}

void mVecPrint(std::vector<int> mVec)
{
	std::vector<int>::iterator ite = mVec.begin() - 1;
	int	i = 0;
	while (++ite != mVec.end())
		std::cout << mVec.at(i++) << " " << std::ends;
}



int	main(int ac, char **av)
{
	std::vector<int> mVec;
	if (ac <= 2)
		return (0);
	if (av_check(av) == false)
		return (1);
	generate(mVec, av);
}
