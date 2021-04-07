#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

void startout(char enter, fstream& start);
void displayMainMenu();


int main() //start works
{
	string Cname;
	fstream start;
	char enter{};
	startout(enter, start);

	cout << "Welcome, Brave Adventurer! What should we call you by when we record you in the annals? ";
	cin.ignore();
	getline(cin, Cname);
	cout << "Welcome, " << Cname << " to Naridge Gatehouse, it is from here that most begin their trial of entry." << endl << endl << "Press any key to enter trial selection";
	system("pause>null");


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
			cout << "You must choose to either undertake the trials, or never return!(Y/N): ";
			cin >> enter;
		} while (enter != 'y' && enter != 'Y' && enter != 'n' && enter != 'N');
	}
	if (enter == 'y' || enter == 'Y')
	{
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

void displayMainMenu()
{
	system("cls");

}