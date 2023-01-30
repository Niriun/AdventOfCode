#include "Day_1.h"

Day_1::Day_1() {
	std::string input = readInput(_inputFile);
	parsedInput = parseInput(input);
}
std::string Day_1::getAnswer() {
	calculateHighestThreeElves(parsedInput);

	return std::to_string(maxMax) + ", " + std::to_string(maxMax + middleMax + minMax);
}

std::vector<std::string>* Day_1::parseInput(std::string input) {
	std::string delimiter = "\n";
	size_t pos = 0;
	std::vector<std::string>* output = new std::vector<std::string>();

	while ((pos = input.find(delimiter)) != std::string::npos) {
		output->push_back(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
	}

	return output;
}

void Day_1::calculateHighestThreeElves(std::vector<std::string>* parsedInput) {
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