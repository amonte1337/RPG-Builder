#pragma once
#include <string>
#include <vector>
#include <fstream>

class Puzzle
{
public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();
	std::string getAsString();
	inline const int& getCorrectAnswer() const { return this->correctAnswer; }

private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;

};

