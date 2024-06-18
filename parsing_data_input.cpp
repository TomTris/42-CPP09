#include "BitcoinExchange.hpp"

bool is_valid_date(std::string const date)
{
	std::stringstream ss;
	int	year;
	int	month;
	int	day;
	std::string str_year = date.substr(0, 4);
	ss << str_year;
	ss >> year;
	std::string str_month = date.substr(5, 2);
	ss << str_month;
	ss >> month;
	std::string str_day = date.substr(8, 2);
	ss << str_day;
	ss >> day;
	if (month > 12 || month == 0 || day >31 || day == 0)
		return false;
	if (day > 31)
		return (false);
	else if (month == 2)
	{
		if ((year % 4 == 0 && month == 2 && day > 29)
			|| (year % 4 != 0 && month == 2 && day > 28))
		return (false);
	}
	else if (month % 2 == 0)
	{
		if (day > 30)
			return (false);
	}
	return (true);
}

bool	valid_data_input(std::string const &actual, std::map<std::string, float> data)
{
	std::string::iterator	ite;

	if (actual.size() < 14)
	{
		data["Error: Too Short line"] = -1;
		std::cerr << "Too short line" << std::endl;
		return (false);
	}
	std::string str = (std::string) actual;

	ite = str.begin();
	for (int i = 0; i != 13; i++)
	{
		if (i == 4 || i == 7)
		{
			if (*ite != '-')
				return (data["Error: Invalid date"] = -1, false);
		}
		else if (i == 10 || i == 12)
		{
			if (*ite != ' ')
				return (data["Error: Invalid date"] = -1, false);
		}
		else if (i == 11)
		{
			if (*ite != '|')
				return (data["Error: Invalid date"] = -1, false);
		}
	}
	std::string price = actual.substr(13, actual.size() - 13);
	if (price.size() == 0)
		std::cerr << "code wrong" << std::endl;
	ite = price.begin();
	if (price.size() == 1 && *ite == '.')
		return (data["Error: Invalid amount of Bitcoin"] = -1, false);
	int	dot_cnt = 0;
	while (ite != price.end())
	{
		if (*ite == '.')
		{
			if (++dot_cnt > 1)
				return (data["Error: Invalid amount of Bitcoin"] = -1, false);
		}
		else if (*ite > '9' || *ite < '0')
			return (data["Error: Invalid amount of Bitcoin"] = -1, false);
		ite++;
	}
	return (true);
}

std::map<std::string, float> data_input(std::string const file_name)
{
	std::string			str;
	std::string			actual;
	std::string			date;
	std::string			value_str;
	std::stringstream	ss;
	float				value_f;
	std::ifstream	infile(file_name.c_str());
	
	std::map<std::string, float> data;
	if (!infile.is_open())
	{
		std::cerr << "Somehow couldn't open input file named " << file_name << std::endl;
		throw Stop();
	}
	std::getline(infile, str);
	if (actualString(str) != "date | value")
	{
		std::cerr << "Is this the input.txt file??" << std::endl;
		std::cerr << "check first line date | value" << std::endl;
		throw Stop();
	}
	while (std::getline(infile, str))
	{
		actual = actualString(str);
		if (valid_data_input(actual, data))
		{
			date = actual.substr(0, 10);
			value_str = actual.substr(13, actual.size() - 13);
			ss << value_str;
			ss >> value_f;
			data[date] = value_f;
		}
	}
	return (data);
}
