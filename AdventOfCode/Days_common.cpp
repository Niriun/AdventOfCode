#include "Days_common.h"
#include <iostream>

Days::Days() {
	_inputStream = new std::ifstream();
}

Days::~Days() {
	if (_inputStream != NULL) {
		delete _inputStream;
	}
}

std::string Days::readInput(std::string inputFileName) {
	_inputStream->open(inputFileName);

	std::string output;

	char c = _inputStream->get();

	while (_inputStream->good()) {
		output += c;
		c = _inputStream->get();
	}

	_inputStream->close();

	return output;
}