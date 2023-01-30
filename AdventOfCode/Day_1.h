#pragma once

#include "Days_common.h"

class Day_1 : public Days
{
public:
	Day_1();
	int getAnswer() override;
	std::string getDayName() override;

private:
	const std::string _dayName = "Day 1";
	const std::string _inputFile = "Day_1.txt";
	std::vector<int> elfCalories;
};
