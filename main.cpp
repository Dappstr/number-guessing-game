#include <iostream>
#include <ctime>

int makeRand()
{
	srand(time(NULL));
	return (int)rand() % 100 + 1;
}

class Computer
{
private:
	static int randNum;

public:
	static int num;
	static int generateNum()
	{
		num = randNum;
		return num;
	}

};
int Computer::randNum = makeRand();
int Computer::num {};

auto playGame (int guessedNum, int generatedNum) -> bool
{
	while (guessedNum != generatedNum)
	{
		std::cout << "Enter guess: ";
		std::cin >> guessedNum;
		if(guessedNum < generatedNum)
		{
			std::cout << "Lower than generated number!\n";
		}
		else if (guessedNum > generatedNum)
		{
			std::cout << "Higher than generated number!\n";
		}
	}
	std::cout << "You win!\n";
	return true;
}

int main()
{
	int guessedNum {};
	int generatedNum {Computer::generateNum()};

	bool gameSwitch (true);
	while (gameSwitch)
	{
		playGame(guessedNum, generatedNum);
		gameSwitch = false;
	}
}
