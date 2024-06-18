#include "BitcoinExchange.hpp"

void	print_calculate(std::map<std::string, float>::const_iterator & ite,
						std::map<std::string, float>::const_iterator & ite_ip)
{
	std::cout << ite_ip->first
	<< " => " << ite_ip->second
	<< " = " << ite->second * ite_ip->second
	<< std::endl;
}

void	find_data(const std::map<std::string, float> & data, const std::map<std::string, float> &data_ip)
{
	std::map<std::string, float>::const_iterator ite_ip = data_ip.begin();
	std::map<std::string, float>::const_iterator ite;
	while (ite_ip != data_ip.end())
	{
		if (ite_ip->first.substr(0, 5) == "Error")
			std::cout << ite_ip->first << std::endl;
		else if (ite_ip->second > 1000)
			std::cout << "Error: Number too large" << std::endl;
		else if (ite_ip->second < 0)
			std::cout << "Error: Number too small" << std::endl;
		else 
		{
			ite = data.find(ite_ip->first);
			if (ite != data.end())
				print_calculate(ite, ite_ip);
			else
			{
				ite = data.lower_bound(ite_ip->first);
				if (ite == data.begin())
					std::cerr << "Error: No data before this date" << std::endl;
				else 
				print_calculate(ite, ite_ip);
			}
		}
		ite_ip++;
	}
}


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "./btc input.txt" << std::endl;
		return (1);
	}
	try{
		std::string data_file_name = "data.csv";
		std::map<std::string, float> data = get_data(data_file_name);
		std::string av1(av[1]);
		std::map<std::string, float> data_ip = data_input(av1);
		find_data(data, data_ip);
	}
	catch (const Stop &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
