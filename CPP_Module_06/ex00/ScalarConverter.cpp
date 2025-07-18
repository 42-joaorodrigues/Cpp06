#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>   // For std::isnan and std::isinf
#include <iomanip>
#include <iostream>
#include <limits>

void ScalarConverter::convert(const std::string& str) {
	double	val = 0;
	bool	is_special = false;

	// Check for empty string
	if (str.empty()) {
		std::cerr << "Error: Empty input" << std::endl;
		return;
	}

	// Parse
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') // Is char
		val = str[1];
	else if (str == "nan" || str == "nanf") {				   // Is nan
		val = std::numeric_limits<double>::quiet_NaN();
		is_special = true;
	} else if (str == "+inf" || str == "+inff") {			   // Is inf
		val = std::numeric_limits<double>::infinity();
		is_special = true;
	} else if (str == "-inf" || str == "-inff") {			   // Is -inf
		val = -std::numeric_limits<double>::infinity();
		is_special = true;
	} else {												   // Is number
		std::string	s = str;
		if (s[s.size() - 1] == 'f')
			s.erase(s.size() - 1);

		// Input validation
		char* endptr;
		val = strtod(s.c_str(), &endptr);

		// Check if conversion was successful and the entire string was processed
		if (*endptr != '\0') {
			std::cerr << "Error: Invalid input '" << str << "'" << std::endl;
			return;
		}
	}

	// Display char
	std::cout << "char: ";
	if (is_special || val < 32 || val > 126 || val != static_cast<int>(val))
		std::cout << (is_special ? "impossible" : "Non displayable");
	else
		std::cout << "\'" << static_cast<char>(val) << "\'";
	std::cout << std::endl;

	// Display int
	std::cout << "int: ";
	if (is_special || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(val);
	std::cout << std::endl;

	// Display float
	std::cout << "float: ";
	if (is_special) {
		if (std::isnan(val))
			std::cout << "nanf";
		else if (std::isinf(val))
			std::cout << (val > 0 ? "+inff" : "-inff");
	} else if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max()) {
		std::cout << "impossible";
	} else {
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f";
	}
	std::cout << std::endl;

	// Display double
	std::cout << "double: ";
	if (is_special) {
		if (std::isnan(val))
			std::cout << "nan";
		else if (std::isinf(val))
			std::cout << (val > 0 ? "+inf" : "-inf");
	} else {
		std::cout << std::fixed << std::setprecision(1) << val;
	}
	std::cout << std::endl;
}
