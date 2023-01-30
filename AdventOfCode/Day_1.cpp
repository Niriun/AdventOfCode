#include "Day_1.h"
#include <iostream>

Day_1::Day_1() {
}

std::string Day_1::getAnswer() {
	std::string input = readInput(_inputFile);

	std::vector<std::string>* splitStrings = getSubStrings(input);

	int elf = 0;

	for (std::string stringToParse : *splitStrings) {
		if (stringToParse == "") {
			if (elf > maxMax) {
				minMax = middleMax;
				middleMax = maxMax;
				maxMax = elf;
			}
			else if (elf > middleMax) {
				minMax = middleMax;
				middleMax = elf;
			}
			else if (elf > minMax) {
				minMax = elf;
			}

			elf = 0;
		}
		else {
			elf += std::stoi(stringToParse);
		}
	}

	return std::to_string(maxMax) + ", " + std::to_string(maxMax + middleMax + minMax);
}

std::vector<std::string>* Day_1::getSubStrings(std::string input) {
	std::string delimiter = "\n";
	size_t pos = 0;
	std::vector<std::string>* output = new std::vector<std::string>();

	while ((pos = input.find(delimiter)) != std::string::npos) {
		output->push_back(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
	}

	return output;
}

std::string Day_1::getDayName() {
	return _dayName;
}