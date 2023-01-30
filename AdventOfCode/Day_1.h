#pragma once

#include "Days_common.h"

class Day_1 : public Days
{
public:
	Day_1();
	std::string getAnswer() override;
	std::string getDayName() override;

private:

	std::vector<std::string>* getSubStrings(std::string input);

	const std::string _dayName = "Day 1";
	const std::string _inputFile = "Day_1.txt";
	std::vector<int> elfCalories;
	int maxMax = 0, middleMax = 0, minMax = 0;
};
