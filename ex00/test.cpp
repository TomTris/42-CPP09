#include "BitcoinExchange.hpp"

#include <iostream>
#include <set>

int main() {
    std::set<int> data;
	data.insert(1);
	data.insert(3);
	data.insert(5);
	data.insert(7);
	data.insert(9);
    int date = 7;

    auto lower = data.lower_bound(date);
    auto upper = data.upper_bound(date);

    std::cout << "Elements in the set: ";
    for (const auto& elem : data) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    if (lower != data.end()) {
        std::cout << "Lower bound of " << date << " is: " << *lower << "\n";
    } else {
        std::cout << "Lower bound of " << date << " is end()\n";
    }

    if (upper != data.end()) {
        std::cout << "Upper bound of " << date << " is: " << *upper << "\n";
    } else {
        std::cout << "Upper bound of " << date << " is end()\n";
    }

    return 0;
}