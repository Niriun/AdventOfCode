#pragma once

#include "CommonImports.h"

class Days abstract
{
public:
	virtual	std::string getAnswer() = 0;
	virtual std::string getDayName() = 0;

protected:
	std::string readInput(std::string inputFileName);
	Days();
	~Days();

private:
	std::ifstream* _inputStream;
};
