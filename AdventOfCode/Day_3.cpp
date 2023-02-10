#include "Day_3.h"
#include <iostream>
#include <map>

const int ASCII_AT_SYMBOL = 64;
const int SPACE_BETWEEN_ASCII_CASES = 6;
const int ALPHABET_LENGTH = 26;
Day_3::Day_3() {
	std::string input = readInput(_inputFile);
	parseInput(input);
}

std::string Day_3::getAnswer() {
	calculateRucksackPacking();
	return std::to_string(part1Answer);
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

void Day_3::calculateRucksackPacking() {
	int total = 0;
	int priorityScore = 0;
	for (std::string line : *parsedInput) {
		int halfway = line.length() / 2;
		std::string firstHalf = line.substr(0, halfway);
		std::string secondHalf = line.substr(halfway, line.length() / 2);
		std::cout << firstHalf.length() << ", " << secondHalf.length() << std::endl;
		std::cout << firstHalf << " , " << secondHalf << std::endl;
		std::set<char>* firstHalfSet = getFirstHalfCharSet(firstHalf);
		char duplicate = getFirstItemAppearingInBothHalves(firstHalfSet, secondHalf);
		std::cout << duplicate << std::endl;
		total += convertCharToScore(duplicate);
	}
	std::cout << priorityScore << std::endl;
	part1Answer = total;
}

std::set<char>* Day_3::getFirstHalfCharSet(std::string firstHalf) {
	std::set<char>* set = new std::set<char>();
	for (size_t i = 0; i < firstHalf.length(); i++) {
		set->emplace(firstHalf.c_str()[i]);
	}
	return set;
}

char Day_3::getFirstItemAppearingInBothHalves(std::set<char>* firstHalfSet, std::string secondHalf) {
	for (size_t i = 0; i < secondHalf.length(); i++) {
		auto ret = firstHalfSet->emplace(secondHalf.c_str()[i]);

		if (!ret.second) {
			return *ret.first;
		}
	}
	return 0;
}

int Day_3::convertCharToScore(char character) {
	character = 'Z';
	int value = ((int)character) - ASCII_AT_SYMBOL;
	if (value > ALPHABET_LENGTH) {
		int retVal = ((value - ALPHABET_LENGTH) - SPACE_BETWEEN_ASCII_CASES);
		return retVal;
	}
	else {
		int retVal = (value + ALPHABET_LENGTH);
		return retVal;
	}
}