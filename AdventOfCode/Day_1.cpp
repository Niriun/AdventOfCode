#include "Day_1.h"

Day_1::Day_1() {
	std::string input = readInput(_inputFile);
	parseInput(input);
}
std::string Day_1::getAnswer() {
	calculateHighestThreeElves();

	return std::to_string(maxMax) + ", " + std::to_string(maxMax + middleMax + minMax);
}

void Day_1::parseInput(std::string input) {
	parsedInput = new std::vector<std::string>();
	std::string delimiter = "\n";
	size_t pos = 0;

	while ((pos = input.find(delimiter)) != std::string::npos) {
		parsedInput->push_back(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
	}
}

void Day_1::calculateHighestThreeElves() {
	int currentElf = 0;
	for (std::string line : *parsedInput) {
		if (line == "") {
			if (currentElf > maxMax) {
				minMax = middleMax;
				middleMax = maxMax;
				maxMax = currentElf;
			}
			else if (currentElf > middleMax) {
				minMax = middleMax;
				middleMax = currentElf;
			}
			else if (currentElf > minMax) {
				minMax = currentElf;
			}

			currentElf = 0;
		}
		else {
			currentElf += std::stoi(line);
		}
	}
};

std::string Day_1::getDayName() {
	return _dayName;
}