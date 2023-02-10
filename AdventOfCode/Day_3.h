#pragma once
#include "Days_common.h"
#include <set>

class Day_3 : public Days
{
public:
	Day_3();
	std::string getAnswer() override;
	std::string getDayName() override;

protected:
	void parseInput(std::string input) override;

private:

	void calculateRucksackPacking();
	std::set<char>* getFirstHalfCharSet(std::string firstHalf);
	char getFirstItemAppearingInBothHalves(std::set<char>* firstHalfSet, std::string secondHalf);
	int convertCharToScore(char character);

	const std::string _dayName = "Day 3";
	const std::string _inputFile = "Day_3.txt";
	int part1Answer;
};
