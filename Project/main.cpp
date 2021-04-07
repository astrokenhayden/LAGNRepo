#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

void startout(char enter, fstream& start);
void displayMainMenu(char menuControl);


int main() 
{
	string Cname;
	fstream start;
	char enter{};
	char menuControl{};
	startout(enter, start);
	cout << "Welcome, Brave Adventurer! What should we call you by when we record you in the annals? ";
	cin.ignore();
	getline(cin, Cname);
	cout << "Welcome, " << Cname << " to Naridge Gatehouse, it is from here that most begin their trial of entry." << endl;
	cout << "Here at the Gatehouse we control all entry to the city through our trials" << endl;
	cout << "It is a simple system, pass all four trials and gain admission, or give up prior and leave in shame" << endl << endl << "Press any key to enter trial selection";;
	system("pause>null");
	
	do
	{
		displayMainMenu(menuControl);
	}while (menuControl != 9);
	
	
	
	
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

void displayMainMenu(char menuControl)
{
	
	
		system("cls");
		cout << "Press the number in the [] in order to select a trial, or check your progress towards admission" << endl << endl;
		cout << "[1] A trial of wits" << endl;
		cout << "[2]" << endl;
		cout << "[3]" << endl;
		cout << "[4]" << endl;
		cout << "[5] Select this to check how many completions you are from finishing; or if finished, to enter the city" << endl;
		cout << "[9] Select this only if you have decided to give up on the trials; There is no going back" << endl << endl;
		cout << "Please select an option: ";
		cin >> menuControl;

		if (menuControl == '1')
		{

		}
		else if (menuControl == '2')
		{

		}
		else if (menuControl == '3')
		{

		}
		else if (menuControl == '4')
		{

		}
		else if (menuControl == '5')
		{

		}
		else if (menuControl == '9')
		{

		}
		else
		{
			cout << "You have made an invalid input. Please Input one of the options" << endl << "Press any key to try again";
			system("pause>null");
			system("cls");
			
		}
	

}