#include <iostream>

using namespace std;

struct GAME {
	string Platform;
	string Name;
	string ReleaseDate;
	string Specification;
	float price;
	bool bought;
};
//data
/*******************/
int index = 1;
float wallet = 0;
bool Create(GAME* games, int& size, string platform, string name, string releaseDate, string specification, float price)
{
	if (size > 99)
	{
		return false;
	}
	games[size].Platform = platform;
	games[size].Name = name;
	games[size].ReleaseDate = releaseDate;
	games[size].Specification = specification;
	games[size++].price = price;
	if (wallet >= price)
	{
		wallet = wallet - price;
		return true;

	}
	else
	{
		for (int i = index; i <= size; i++)
		{
			games[i] = games[i + 1];
		}
		size--;
		return false;

	}
}




void RemoveGame(GAME* games, int& size, int index)
{
	cout << "Choose the index of the game you want to remove from the cart(the first number is the index) \n\n";
	cin >> index;
	for (int i = index; i <= size; i++)
	{
		games[i] = games[i + 1];
	}
	size--;

}
/*******************/

//presentation
/*******************/


void ShowAllGames(GAME* games, int& size)
{
	string message = "\nList of all the games: \n";
	cout << message;
	cout << "Choose a game by its index (the first number).\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << " " << i + 1 << ". " << games[i].Platform << " , " << games[i].Name << " , " << games[i].ReleaseDate << " , " << games[i].Specification << " , " << games[i].price << " - ";
		if (games[i].bought)
		{
			cout << "bought  " << endl;
		}
		else
		{
			cout << "free  " << endl;
		}

	}
}


void EnterGameDetails(GAME* games, int& size)
{
	cout << "OK, now enter your game data in this order:\nPlatform; Name; Release date; Specification; price " << endl;
	string platform, name, releaseDate, specification;
	float  price;
	cin >> platform >> name >> releaseDate >> specification >> price;
	if (Create(games, size, platform, name, releaseDate, specification, price))
	{
		cout << "Successfully purchased! " << endl;
	}
	else
	{
		cout << "Sorry, you don't have enough money!" << endl << "Try adding some more! " << endl;
	}

}

bool MainMenu(GAME* games, int& size)
{
	int index = 1;
	cout << "\nList: \n 1.Add money to your wallet.\n 2.See your balance.\n 3.Purchase a game. \n 4.See all games. \n 5.Return a game. \n 6.Quit \n\n";


	int n;
	cin >> n;
	switch (n)
	{
		{
	case 1:
	{
		int newMoney;
		cout << "How much money do you want to add?" << endl << "Add:";
		cin >> newMoney;
		wallet = newMoney + wallet;
		cout << "Money added!" << endl << endl;
	}
	case 2:
	{
		cout << "Your balance is " << wallet << "$ !" << endl;
		return true;
	}
	case 3:
	{
		EnterGameDetails(games, size);
		return true;
	}


	case 4:
	{
		ShowAllGames(games, size);
		return true;
	}
	case 5:
	{
		cout << "Choose the game you wish to return:";
		ShowAllGames(games, size);
		RemoveGame(games, size, index);
		return true;
	}
	case 6:
	{
		return false;
	}
	default:
	{
		cout << "Error. Please enter again." << endl;
		return true;
	}

		}
	}
}



void Greetings()
{
	string hello = "Hello!\nWelcome to GameZone!\nChoose an option from the main menu down below. \n\n";
	cout << hello;
}

/*******************/

int main()
{
	GAME games[1000];
	string quit = "OK, bye! Have a nice day\n";
	int size = 0;
	Greetings();
	while (MainMenu(games, size));
	cout << quit;
}