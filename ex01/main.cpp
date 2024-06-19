#include "RPN.hpp"
#include <sstream>
#include <stack>

int	iteToInt(std::string::iterator ite)
{	return *ite = '0'; }

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

int	ret(int a, int b, std::string::iterator ite)
{
	int ret;
	if (*ite == '+')
		ret = b + a;
	else if (*ite == '-')
		ret = b - a;
	else if (*ite == '*')
		ret = b * a;
	else
		ret = b / a;
	return ret;
}

int	main(int ac, char **av)
{
	int	a;
	int b;
	if (ac != 2)
		return (eprint("./RPN \"Numbers and signs here\""));
	std::stack<int> mStack;
	std::string str = actualString(static_cast<std::string>(av[1]));
	std::string::iterator ite = str.begin() - 1;
	while (++ite != str.end())
		if (!std::isdigit(*ite) && *ite != ' ' && *ite != '+'
			&& *ite != '-' && *ite != '*' && *ite != '/')
			return (eprint("Invalid character"));
	ite = str.begin() - 1;
	while (++ite != str.end())
	{
		if (std::isdigit(*ite))
			mStack.push(iteToInt(ite));
		else if (*ite == '+' || *ite == '-' || *ite == '*' || *ite == '/')
		{
			if (mStack.size() < 2)
				return (eprint("can't calculate with only 1 number left"));
			a = mStack.top();
			mStack.pop();
			b = mStack.top();
			mStack.pop();
			if (a == 0 && *ite == '/')
				return (eprint("can't divided by 0"));
			mStack.push(ret(a, b, ite));
		}
	}
	if (mStack.size() > 1)
		return (eprint("Not enough signs"));
	std::cout << mStack.top() << std::endl;
	return (0);
}