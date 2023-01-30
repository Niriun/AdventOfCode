#include "Day_1.h"
#include <iostream>

Day_1::Day_1() {
}

int Day_1::getAnswer() {
	std::string input = readInput(_inputFile);
	std::cout << input << std::endl;
	std::vector<std::string>* subStrings = new std::vector<std::string>();
	std::string delimiter = " ";
	int index = 0;
	size_t pos = 0;

	while ((pos = input.find(delimiter)) != std::string::npos) {
		subStrings->push_back(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
	}

	for (std::string subString : *subStrings) {
		std::cout << subString << std::endl;
	}

	return 0;
}

std::string Day_1::getDayName() {
	return _dayName;
}