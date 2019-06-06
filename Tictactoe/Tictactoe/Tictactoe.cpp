#include <iostream>
#include <string>
using namespace std;
int gamemode, n, turn = rand() % 2, result = 3, slot = 0;
char **a;
char p1[20], p2[20], record[2];
void CreateBoard()
{
	cout << "Enter size of board: ";
	cin >> n;
	a = new char*[n];
	for (register int i = 0; i < n; i++)
		a[i] = new char[n];
	for (register int i = 0; i < n; i++)
		for (register int j = 0; j < n; j++)
			a[i][j] = ' ';
}
void Marking()
{
	register int i = record[0] - 48;
	register int j = record[1] - 48;
	if (turn)
	{
		a[i - 1][j - 1] = 'X';
		turn = false;
	}
	else
	{
		a[i - 1][j - 1] = 'O';
		turn = true;
	}
}
void ShowCurrentBoard()
{
	string str = "";
	register int count = n * 4 + 1;
	while (count != 0)
	{
		str += "-";
		count--;
	}
	for (register int i = 0; i < n; i++)
	{
		cout << str << "\n";
		for (register int j = 0; j <= n * 4; j++)
		{
			if (j == 0) cout << "|";
			else if (j % 4 == 2) cout << a[i][j / 4];
			else if (j % 4 != 0)cout << " ";
			else cout << "|";
		}
		cout << "\n";
	}
	cout << str << "\n";;
}
void Check()
{
	
}
void Playing()
{
	while (result == 3)
	{
		system("cls");
		ShowCurrentBoard();
		cout << "Your Turn ";
		if (turn) cout << p1 << ": ";
		else cout << p2 << ": ";
		cin.ignore();
		cin >> record;
		Marking();
	}
}
void Game()
{
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin >> gamemode;
	switch (gamemode)
	{
	case 1:
		cout << "Enter Player 1 Name: ";
		cin.ignore();
		cin.get(p1, 20);
		cout << "Enter Player 2 Name: ";
		cin.ignore();
		cin.get(p2, 20);
		CreateBoard();
		Playing();
		system("cls");
		ShowCurrentBoard();
		cout << "******************************************************************\n";
		if (result == 2) cout << "DRAW\n";
		else if (result == 0) cout << "PLAYER 1 WIN\n";
		else if (result == 1) cout << "PLAYER 2 WIN\n";
		turn = rand() % 2;
		result = 3;
		break;
	default:
		break;
	}
}
void main()
{
	cout << "Welcome To Tic-tac-toe game! Play with your way!\n";
	cout << "If you find any problem, please contact tronghieu8531@gmail.com\n";
	cout << "******************************************************************\n";
	Game();
	while (gamemode == 1)
	{
		cout << "DO YOU WANT PLAY AGAIN! (1 - ONCE MORE!, OTHERS - EXIT GAME): ";
		cin >> gamemode;
		if (gamemode != 1)
			break;
		else
		{
			system("cls");
			Game();
		}
	}
}
