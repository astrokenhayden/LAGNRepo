#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

void startout(char enter, fstream& start);


int main()
{
	string Cname;
	fstream start;
	char enter{};
	startout(enter, start);

	cout << "Brave Adventurer! What should we call you by when we record you in the annals? ";
	cin.ignore();
	getline(cin, Cname);
	cout << "Welcome, " << Cname << " to Boburg, it is from here that most begin their journey of the ages." << endl << endl;



	system("pause");
	return 0;
}



void startout(char enter, fstream& start)
{


	start.open("start.txt", ios::in);
	if (start.fail())
	{
		cout << "start.txt failed to open, please check the file." << endl << "Press any key to leave the program.";
		system("pause>null");
		exit(0);
	}
	else
	{
		cout << start.rdbuf();
	}
	cin >> enter;
	if (enter != 'y' && enter != 'Y' && enter != 'n' && enter != 'N')
	{
		do
		{
			cout << "You must choose to either undertake the journey, or never return!(Y/N): ";
			cin >> enter;
		} while (enter != 'y' && enter != 'Y' && enter != 'n' && enter != 'N');
	}
	if (enter == 'y' || enter == 'Y')
	{
		system("cls");
		cout << "\n\nBest of luck on your journey!!!";
		cout << "\nPress any key to begin" << endl;
		system("pause>null");
		system("cls");

	}
	else
	{
		cout << "\nA sad day indeed, though perhaps, the decision shows wisdom beyond the average soul." << endl << "Go on, live your life, do not regret the choice you made here today." << endl;
		cout << "Press any key to leave";
		system("pause>null");
		exit(1);


	}



}