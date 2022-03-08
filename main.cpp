#include <iostream>
#include <ctime>
#include <string>

class Computer
{
private:
	int m_randNum {};

public:
	void setRandNum();

	int getComputerNum() const
	{
		return m_randNum;
	}

};

void Computer::setRandNum()
{
	srand(time(NULL));
	int num{ rand() % 100 + 1 };

	this->m_randNum = num;
}

auto playGame(std::string& input, const int& generatedNum) -> bool
{
	std::cout << "Enter 'e' to exit\n";
	int inputToGuess {};

	do
	{
		std::cout << ">> ";
		std::cin >> input;
		{
			if (input == "e" || input == "E")
			{
				std::cout << "Exiting.\n";
				return false;
			}
			try
			{
				inputToGuess = std::stoi(input);
			}

			catch (std::exception& e)
			{
				std::cout << "Input misunderstood: " << e.what() << '\n';
			}
		}

		if (inputToGuess < generatedNum)
		{
			std::cout << "Lower than generated number!\n";
		}

		else if (inputToGuess > generatedNum)
		{
			std::cout << "Higher than generated number!\n";
		}

	} while (inputToGuess != generatedNum);

	std::cout << "You win!\n";
	return true;
}

int main()
{
	std::string input    {};
	Computer computerObj {};

	bool gameSwitch(true);

	while (gameSwitch)
	{
		computerObj.setRandNum();
		int randNum{ computerObj.getComputerNum()};

		playGame(input, randNum);

		std::cout << "Continue playing? (y/n)";
		std::cin >> input;

		if (input == "y" || input == "Y")
		{
			computerObj.setRandNum();
		}

		else if(input == "n" || input == "N")
		{
			gameSwitch = false;
		}

		else
		{
			std::cout << "Input not recognized. Continuing anyway.\n";
		}
	}
}
