#include "Puzzle.h"

Puzzle::Puzzle(std::string fileName)
{
	this->correctAnswer = 0;

	std::ifstream infile(fileName);

	int numOfAns = 0; //number of answers
	std::string answer = "";

	if (infile.is_open())
	{
		std::getline(infile, this->question);
		infile >> numOfAns;
		infile.ignore();

		for (size_t i = 0; i < numOfAns; i++)
		{
			std::getline(infile, answer);
			this->answers.push_back(answer);
		}

		infile >> correctAnswer;
		this->correctAnswer = correctAnswer;
		infile.ignore();
	}
	else
		throw("Could not open puzzle!");

	infile.close();
}

Puzzle::~Puzzle() //virtual deconstructor
{
	//something is supposed to go here :P
}

std::string Puzzle::getAsString()
{
	std::string answers = "";

	for (size_t i = 0; i < this->answers.size(); i++)
	{

		answers += std::to_string(i+1) + ": " + this->answers[i] + '\n';
	}

	/*return this->question + '\n' + '\n' +
	answers + '\n' + 
	std::to_string(this->correctAnswer) + '\n';*/

	return this->question + '\n' + '\n' +
		answers + '\n';
}