#include "Day_3.h"

Day_3::Day_3() {
	std::string input = readInput(_inputFile);
	parseInput(input);
}

std::string Day_3::getAnswer() {
	return "0";
};

std::string Day_3::getDayName() {
	return _dayName;
};

void Day_3::parseInput(std::string input) {
	parsedInput = new std::vector<std::string>();
	std::string delimiter = "\n";
	size_t pos = 0;

	while ((pos = input.find(delimiter)) != std::string::npos) {
		parsedInput->push_back(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
	}
	parsedInput->push_back(input);
};