#include "BitcoinExchange.hpp"

bool	valid_data(std::string const &actual)
{
	std::string::iterator	ite;
	int						dot_cnt = 0;

	if (actual.size() < 12)
	{
		std::cerr << "Error: Too short line1" << std::endl;
		return (false);
	}
	if (!is_valid_date(actual))
		return (false);
	std::string str = (std::string) actual;

	ite = str.begin();
	for (int i = 0; ite != str.end(); i++)
	{
		if (i == 4 || i == 7 || i == 10)
		{
			if (i == 4 || i == 7)
			{
				if (*ite != '-')
					return (std::cerr << "Not valid date" << std::endl, false);
			}
			else if (*ite != ',')
				return (std::cerr << "Not valid info" << std::endl, false);
		}
		else
		{
			if (*ite == '.')
			{
				if (++dot_cnt > 1)
					return (std::cerr << "Not valid year" << std::endl, false);
			}
			else if (*ite > '9' || *ite < '0')
				return (std::cerr << "Not valid year" << std::endl, false);
		}
		ite++;
	}
	return (true);
}

float	str_to_float(std::string str)
{
	std::stringstream ss;
	float ret;

	ss << str;
	ss >> ret;
	return ret;
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
		throw StopF();
	}
	if (!infile.is_open())
	{
		std::cerr << "Somehow couldn't open " << file_name << std::endl;
		throw StopF();
	}
	std::getline(infile, str);
	if (actualString(str) != "date,exchange_rate")
	{
		std::cerr << "Is this the data.csv file??" << std::endl;
		infile.close();
		throw StopF();
	}
// int	i = 0;
	while (std::getline(infile, str))
	{
		actual = actualString(str);
		if (!valid_data(actual))
		{
			std::cerr << "Somehow, there is/are invalid input in data.csv file!" << std::endl;
			infile.close();
			throw StopF();
		}
		date = actual.substr(0, 10);
		value_str = actual.substr(11, actual.size() - 11);
		value_f = str_to_float(value_str);
		data[date] = value_f;
	}
	infile.close();
	return (data);
}