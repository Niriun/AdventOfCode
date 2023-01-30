#include "Day_2.h"

Day_2::Day_2() {
	std::string input = readInput(_inputFile);
	parseInput(input);
}

std::string Day_2::getAnswer() {
	calculateTotalScore();
	rigTheGame();
	return std::to_string(part1answer) + ", " + std::to_string(part2answer);
};

std::string Day_2::getDayName() {
	return _dayName;
};

void Day_2::rigTheGame() {
	for (std::string line : *parsedInput) {
		int opponentScore = charToNumberMap.at(line.substr(0, 1).c_str()[0]);
		int playerScore = charToNumberMap.at(line.substr(2, 1).c_str()[0]);
		part2answer += getRiggedAnswer(opponentScore, playerScore);
	}
}

int Day_2::getRiggedAnswer(int opponent, int player) {
	switch (player) {
	case 1: {
		return ((opponent + 1) % 3) + 1;
	}
	case 2: {
		return opponent + 3;
	}
	case 3: {
		switch (opponent) {
		case 1: {
			return 8;
		}
		case 2: {
			return 9;
		}
		case 3: {
			return 7;
		}
		}
	}
	}
}

void Day_2::calculateTotalScore() {
	for (std::string line : *parsedInput) {
		int opponentScore = charToNumberMap.at(line.substr(0, 1).c_str()[0]);
		int playerScore = charToNumberMap.at(line.substr(2, 1).c_str()[0]);
		part1answer += getScoreForRound(opponentScore, playerScore);
	}
}

int Day_2::getScoreForRound(int opponent, int player) {
	if (opponent == player) {
		return (player + 3);
	}
	if ((opponent + player) == 4) {
		return opponent > player ? (player + 6) : player;
	}

	return player > opponent ? (player + 6) : player;
}

void Day_2::parseInput(std::string input) {
	parsedInput = new std::vector<std::string>();
	std::string delimiter = "\n";
	size_t pos = 0;

	while ((pos = input.find(delimiter)) != std::string::npos) {
		parsedInput->push_back(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
	}
	parsedInput->push_back(input.substr(0, 3));
};