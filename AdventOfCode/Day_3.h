#pragma once
#include "Days_common.h"
class Day_3 : public Days
{
public:
	Day_3();
	std::string getAnswer() override;
	std::string getDayName() override;

protected:
	void parseInput(std::string input) override;

private:
	const std::string _dayName = "Day 3";
	const std::string _inputFile = "Day_3.txt";
};
