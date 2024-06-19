#include "BitcoinExchange.hpp"

bool is_valid_date(std::string const date_o)
{
	std::string date = (std::string) date_o;
	int	year = strToInt(date.substr(0, 4));
	int	month = strToInt(date.substr(5, 2));
	int	day = strToInt(date.substr(8, 2));
	if (month > 12 || month == 0 || day > 31 || day == 0)
		return false;
	else if (month == 2)
	{
		if ((day > 29) || (year % 4 != 0 && month == 2 && day > 28))
			return (false);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30)
			return (false);
	return (true);
}

int end_print(std::string date, std::string bit_amount, float price)
{
	float amount = strToFloat(bit_amount);
	if (amount > 1000)
		return (mprint_invalid_amount());
	std::cout << date << " " << " => " << amount << " = " << price * amount << std::endl;
	return (1);
}

int	find_n_print(std::map<std::string, float> data, std::string date, std::string final)
{
	std::map<std::string, float>::iterator data_ite = data.find(date);
	if (data_ite == data.end())
	{
		data_ite = data.upper_bound(date);
		if (data_ite == data.begin())
			return (mprint("Error: Time is too early"));
		data_ite--;
		end_print(data_ite->first, final, data_ite->second);
	}
	else
		end_print(data_ite->first, final, data_ite->second);
	return (1);
}

int	find_data(std::map<std::string, float> data, std::string str)
{
	std::string actual = actualString(str);
	if (actual.size() < 12)
		return (mprint("Error: Line too short"));
	std::string date = actual.substr(0, 10);
	if (is_valid_date(date) == false)
		return (mprint("Error: Invalid date"));
	std::string left = actual.substr(10, actual.size() - 10);
	std::string::iterator ite = left.begin();
	std::string::iterator ite2 = ite;
	if (*ite == ' ')
		ite++;
	if (*ite != '|')
		return (mprint("Error: pipe | ?"));
	ite++;
	if (*ite == ' ')
		ite++;
	if (*ite == '+' || *ite == '-')
	{
		ite++;
		if (*(ite - 1) == '-')
		{
			if (ite == left.end())
				return (mprint_invalid_amount());
			while (ite != left.end())
			{
				if (*ite != '0')
					return (mprint_invalid_amount());
				ite++;
			}
			return (find_n_print(data, date, "0"));
		}
	}
	std::string final = left.substr(ite - ite2, left.size() - (ite - ite2));
	int	dot_cnt = 0;
	ite = final.begin();
	if (final.size() == 0 || (final.size() == 1 && *ite == '.'))
		return (mprint_invalid_amount());
	while (ite != final.end())
	{
		if (*ite == '.')
		{
			if (++dot_cnt == 2)
				return (mprint_invalid_amount());
		}
		else if (!std::isdigit(*ite))
		{
			return (mprint_invalid_amount());
		}
		ite++;
	}
	return find_n_print(data, date, final);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (mprint("./btc input.txt"), 0);
	
	try
	{
		std::map<std::string, float> data = get_data("data.csv");
		std::ifstream infile(av[1]);
		if (!infile.is_open())
		{
			std::cout << "Coudn't open " << av[1] << std::endl;
			throw StopF();
		}
		std::string str;
		std::getline(infile, str);
		while (std::getline(infile, str))
			find_data(data, str);
		infile.close();
	}
	catch (const StopF &e)
	{
		return (std::cerr << e.what() << std::endl, 1);
	}
}
