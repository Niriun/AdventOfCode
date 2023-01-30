#pragma once

#include <map>

#include "Days_common.h"

class Day_2 : public Days
{
public:
	Day_2();
	std::string getAnswer() override;
	std::string getDayName() override;

private:

	void calculateTotalScore();
	void rigTheGame();
	int getRiggedAnswer(int opponent, int player);
	int getScoreForRound(int opponent, int player);
	void parseInput(std::string input) override;

	int part1answer;
	int part2answer;
	const std::string _dayName = "Day 2";
	const std::string _inputFile = "Day_2.txt";
	const std::map<char, int> charToNumberMap{ { 'A',1 }, { 'B',2 }, { 'C',3 }, { 'X',1 }, { 'Y',2 }, { 'Z',3 } };
};
