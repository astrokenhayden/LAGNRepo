#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
const int necessaryCompletions = 4;
char menuControl{};
void startout(char enter, fstream& start);
void displayMainMenu(int&);
int incrementCompletions(int&);
void enterNaridge();
int cowardlyExit();

int main() 
{
	string Cname;
	int successfulCompletions = 0;
	fstream start;
	char enter{};
	
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
		displayMainMenu(successfulCompletions);
	}while (menuControl != 9);
	
	
	
	
	system("pause>null");
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

void displayMainMenu(int& successfulCompletions)
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

		switch (menuControl)
		{
		case '1':
		{
			incrementCompletions(successfulCompletions);
			break;
		}
		case '2':
		{
			break;
		}
		case '3':
		{
			break;
		}
		case '4':
		{
			break;
		}
		case '5':
		{
			if (successfulCompletions == 4)
			{
				enterNaridge();
			}
			else
			{
				cout << "\nYou have not collected enough completion plaques yet:" << endl << endl;
				if (successfulCompletions == 1)
				{
					cout << "You current have 1 plaque.";
				}
				else
				{
					cout << "You currently have " << successfulCompletions << " plaques.";
				}
				if (necessaryCompletions - successfulCompletions == 1)
				{
					cout << " You need 1 more plaque to gain entry to the city." << endl;
				}
				else
				{
					cout << " You need " << necessaryCompletions - successfulCompletions << " more plaques to gain entry to the city." << endl;
				}
			}
			system("pause");
			break;
		}
		case '9':
		{
			cowardlyExit();
			break;
		}
		default:
		{
			cout << "This is an invalid input, Please select a correct one next time";
			system("pause>null");
			system("cls");
		}
		}

}

int incrementCompletions(int &successfulCompletions)
{
	successfulCompletions += 1;
	return successfulCompletions;
}

void enterNaridge()
{
	char enterNar{};
	cout << "\n\nCongratualtions!!!!! You have succesfully passed the four entrance trials" << endl;
	cout << "\n[1] If you would like to provide feedback on the trials prior to entering the city" << endl;
	cout << "[2] If you would prefer to enter the city without providing feedback";
	cout << "\n\nPlease select your method of entry: ";
	cin >> enterNar;

	switch (enterNar)
	{
	case 1: 
	{
		// needs feedback function
		break;
	}
	case 2:
	{
		//needs complimentary exit
		break;
	}
	}

}
int cowardlyExit()
{
	system("cls");
	cout << "So this is the way it ends..." << endl << "Go, Leave this place and never return" <<endl << endl << "Press any key to get out of my sight";
	menuControl = 9;
	return 0;
}