#include "BitcoinExchange.hpp"

bool	valid_data(std::string const &actual)
{
	std::string::iterator	ite;

	if (actual.size() < 12)
	{
		std::cerr << "Too short line" << std::endl;
		return (false);
	}
	std::string str = (std::string) actual;

	ite = str.begin();
	for (int i = 0; ite != str.end(); i++)
	{
		if (i == 4 || i == 7 || i == 9)
		{
			if (i == 4 || i == 7)
			{
				if (*ite != '-')
				{
					std::cerr << "Not valid date" << std::endl;
					return (false);
				}
			}
			else if (*ite != ',')
			{
				std::cerr << "Not valid date" << std::endl;
				return (false);
			}
		}
		else if (*ite > '9' || *ite < '0')
		{
			std::cerr << "Not valid year" << std::endl;
			return (false);
		}
	}
	return (true);
}

std::map<std::string, float>	get_data(std::string const &file_name)
{
	std::string			str;
	std::string			actual;
	std::string			date;
	std::string			value_str;
	std::stringstream	ss;
	float				value_f;
	std::ifstream	infile(file_name.c_str());
	
	std::map<std::string, float> data;

	if (file_name != "data.csv")
	{
		std::cerr << file_name << " not found!" << std::endl;
		throw Stop();
	}
	if (!infile.is_open())
	{
		std::cerr << "Somehow couldn't open " << file_name << std::endl;
		throw Stop();
	}
	std::getline(infile, str);
	if (actualString(str) != "date | value")
	{
		std::cerr << "Is this the data.csv file??" << std::endl;
		throw Stop();
	}
	while (std::getline(infile, str))
	{
		actual = actualString(str);
		if (!valid_data(actual))
		{
			std::cerr << "Somehow there is/are invalid input in data.csv file!" << std::endl;
			throw Stop();
		}
		date = actual.substr(0, 10);
		value_str = actual.substr(11, 1);
		ss << value_str;
		ss >> value_f;
		data[date] = value_f;
	}
	return (data);
}