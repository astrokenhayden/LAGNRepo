#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
//global variables
bool hangmanCompleted = FALSE;
bool kendraCompleted = FALSE;
bool garrettCompleted = FALSE;
bool nateCompleted = FALSE;
const int necessaryCompletions = 4;
char menuControl{};
//functions
void startout(char enter, fstream& start, string& Cname); //+1 void function passes by value and reference
void displayMainMenu(int&, string&);					  //+1 void function
void enterNaridge(string&);
void writeFeedback();
void displaygarrettsSegment();
void rollDie();
int incrementCompletions(int&);							  //+1 value returning
int cowardlyExit(string&);
//class declaration for hangman
class hangman											  //+1 class
{//coded By: Luke Martin
public:
	int letterFill(char, string, string&);				  
	void playhangman(int&, string&);
	void wordManip(char&, string&);
private:
	static const int ARRSIZE = 30;
	int i = 0;
	const int MAX_TRIES = 5;
	char letter{};
	int wrong_guess = 0;
	string guesses;
	string word;
	string words[ARRSIZE];										//+1 one dimensional array
	fstream hangmanwords;
};

string Cname; //Made this a global to work with Garrett's story function

int main() 
{
	//variables
	fstream start;
	int successfulCompletions = 0;
	char enter{};

	startout(enter, start, Cname);
	do                                                    //Do-While Repetition Structure +1
	{
		displayMainMenu(successfulCompletions, Cname);
	}while (menuControl != 9);//end do while
	
	
	system("pause>null");
	return 0;
}

void startout(char enter, fstream& start,string& Cname)  
{
	//Coded by: Luke Martin
	start.open("start.txt", ios::in);   //inputs initial output/setsup story +1 imput file
	if (start.fail())					//error checks if file					
	{
		cout << "start.txt failed to open, please check the file." << endl << "Press any key to leave the program.";
		system("pause>null");
		exit(0);
	}
	else								//outputs in color
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "\n"<< start.rdbuf();
		start.close();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "Are you amoungst the bravest of souls who will attempt this trial ? (Y / N) : ";
	}//end if else
	cin >> enter;
										//if structure to enter next section
	if (enter != 'y' && enter != 'Y' && enter != 'n' && enter != 'N')
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		do																							//Do-While Repetition Structure +1
		{
			cout << "You must choose to either undertake the trials, or never return!(Y/N): ";
			cin >> enter;
		} while (enter != 'y' && enter != 'Y' && enter != 'n' && enter != 'N');//end do while
	}
	else if (enter == 'y' || enter == 'Y')
	{//prompts user to enter their name, and provides information on how the Trials system functions
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		system("cls");
		cout << "\nWelcome, Brave Adventurer! What should we call you by when we record you in the annals? ";
		cin.ignore();
		getline(cin, Cname);
		cout << "\n***********************************************************************************************************************";
		cout << "\nWelcome, " << Cname << " to Naridge Gatehouse, it is from here that most begin their trial of entry." << endl;
		cout << "Here at the Gatehouse we control all entry to the city through our trials." << endl;
		cout << "It is a simple system; pass all four trials, each earning you a completion plaque." << endl << "Turn 4 plaques in at the Gatehouse and obtain entry, or give up prior and leave in shame." << endl;
		cout << "***********************************************************************************************************************";
		cout << "\n\nPress any key to enter trial selection";
		system("pause>null");
	}
	else
	{//allows for user to leave the program before reaching the trials
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "\n__________________________________________________________________________________________________________";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "\n\nA sad day indeed, though perhaps, the decision shows wisdom beyond the average soul." << endl << "Go on, live your life, do not regret the choice you made here today." << endl;
		cout << "Press any key to leave";
		system("pause>null");
		exit(0);
	}//end else if
}

void displayMainMenu(int& successfulCompletions, string& Cname)
{
	/*coded by: Luke Martin
	Displays the Menu, and contains the switch structure that runs the program*/
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "\nPress the number in the [] in order to select a trial, or check your progress towards admission\nEach trial may only be completed once.";
		cout << "\n__________________________________________________________________________________________________________" << endl << endl;
		cout << "[1] A trial of Words and Wits" << endl;
		cout << "[2]" << endl;
		cout << "[3]" << endl;
		cout << "[4]" << endl;
		cout << "[5] Select this to check how many completions you are from finishing; or if finished, to enter the city" << endl;
		cout << "[9] Select this only if you have decided to give up on the trials; There is NO going back" << endl << endl;
		cout << "Please select an option: ";
		cin >> menuControl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		switch (menuControl)//switch structure
		{
		case '1':
		{//if elsethat begins the "hangman" game, has a boolean that prevents trials from being completed more than once
			if (hangmanCompleted == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "\nYou have already completed this Trial, you cannot retake a completed Trial." << "\nPress any key to return to Trial selection";
				system("pause>null");
			}
			else
			{
				hangman t;
				t.playhangman(successfulCompletions, Cname);
			}
			
			break;
		}
		case '2':
		{
			if(kendraCompleted == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "\nYou have already completed this Trial, you cannot retake a completed Trial." << "\nPress any key to return to Trial selection";
				system("pause>null");
			}
			else
			{
				incrementCompletions(successfulCompletions);
			}
			
			break;
		}
		case '3':
		{
			if(garrettCompleted==TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "\nYou have already completed this Trial, you cannot retake a completed Trial." << "\nPress any key to return to Trial selection";
				system("pause>null");
			}
			else
			{

			}
			break;
		}
		case '4':
		{
			if(nateCompleted==TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "\nYou have already completed this Trial, you cannot retake a completed Trial." << "\nPress any key to return to Trial selection";
				system("pause>null");
			}
			else
			{

			}
			break;
		}
		case '5':
		{//Used to "win" the journey, each program increments a value when successfully completed.
		 //When equal to 4 you can move you, otherwise tells user how many more completions they need.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			if (successfulCompletions == 4)
			{
				enterNaridge(Cname);
			}
			else
			{
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				if (successfulCompletions == 1)
				{
					cout << "You currently have 1 plaque.";
				}
				else
				{
					cout << "You currently have " << successfulCompletions << " plaques.";
				}
				if (necessaryCompletions - successfulCompletions == 1)
				{
					cout << " You need 1 more plaque to gain entry to the city." << "\n\nPress any key to return to the menu";
				}
				else
				{
					cout << " You need " << necessaryCompletions - successfulCompletions << " more plaques to gain entry to the city." << "\n\nPress any key to return to the menu";
				}
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			}
			system("pause>null");
			break;
		}
		case '9':
		{//exit if the user gives up before completing the 4 trials
			cowardlyExit(Cname);
			break;
		}
		default:
		{//prevents the user from breaking the program through invalid inputs
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "\nThis is an invalid input; Please select a correct one next time." <<endl;
			cout << "Make an input to get another chance.";
			system("pause>null");
			system("cls");
		}
		}//end switch

}

int incrementCompletions(int &successfulCompletions)
{//coded by: Luke Martin
 //Simple function that increments the "plaque" count, to be called in the successful running of each person's game
	successfulCompletions += 1;
	return successfulCompletions;
}

void enterNaridge(string& Cname)
{
	//coded by: Luke Martin
	//called when all 4 plaques have been obtained
	//local varialbe for program execution
	char enterNar{};
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	//output
	cout << "\n***********************************************************************************************************************";
	cout << "\n\t\t\t\t\t\tCongratulations!!!!!\n\n" << Cname <<", you have succesfully passed the four entrance trials!" << endl;
	cout << "\n[1] If you would like to provide feedback on the trials prior to entering the city" << endl;
	cout << "[2] If you would prefer to enter the city without providing feedback";
	cout << "\n***********************************************************************************************************************";
	cout << "\n\nPlease select your method of entry: ";
	cin >> enterNar;
	
	switch (enterNar)											//Switch Structure
	{
	case '1': 
	{//this option allows for the user to provide feedback on the program
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n***********************************************************************************************************************\n";
		//calls function for feedback
		writeFeedback();
		cout << "Thank you so much for your feedback. We hope your life in Naridge is fruitful!" << endl;
		cout << "*Program will close on keyboard input*";
		system("pause>null");
		exit(1);
		break;
	}
	case '2':
	{//option allows for the user to skip feedback and exit the program
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\nPlease go right through then, I hope your time in Naridge is everything you dreamed of; you've certainly earned it." << endl << endl; 
		cout << "*Program will close on keyboard input*";
		system("pause>null");
		exit(1);
		break;
	}
	default:
	{//error checking
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "\nThis is an invalid input, Please select a correct one next time" << endl;
		cout << "Make an input to get another chance";
		system("pause>null");
		system("cls");
		enterNaridge(Cname);
	}
	}//end switch

}
void writeFeedback()
{//coded by: Luke Martin
 //takes user's input, and keeps it in a file FeedbackOut
	string feedback;
	fstream feedbackOut;
	feedbackOut.open("FeedbackOut.txt", ios::out);						//+1 output file
	if (feedbackOut.fail())//checks for failed opening of file
	{//output exits program if input file doesn't open
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Advice.txt failed to open, Feedback will not be available at this time. " << endl;
		cout << "Congratulations again on surpassing the trials, sorry our feedback system was not functional" << endl;
		cout << "Have a great time! (Make any input to enter Naridge)";
		system("pause>null");
		exit(1);
	}
	else
	{
		//provides instruction for the user
		cout << "\nPlease enter your feedback below. Your feedback may be as long as you need," << endl;
		cout << "and you can press the <Enter> key one time to type on the next line," << endl;
		cout << "and input the <Enter> key twice to indicate the end of the input:" << endl;
		cout <<"_______________________________________________________________________________________________________________________" << endl<<endl;
		//clear whitespace after using cin, in order to use getline 
		cin.ignore();
		getline(cin, feedback);
		while (feedback.length() > 0)								//While-Loop repetition
		{
			feedbackOut << feedback << endl;
			getline(cin, feedback);
		}//end while
		cout << "***********************************************************************************************************************" << endl << endl;
		feedbackOut.close();
	}

}
int cowardlyExit(string& Cname)
//coded by Luke Martin
//function that is called if user leaves the program without obtaining 4 completions
{
	//makes name uppercase to indicate anger
	for_each(Cname.begin(), Cname.end(), [](char& c) 
		{
		c = toupper(c);												//+ 1 string operation
		});

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	cout << "\n\nSo this is the way it ends...\n" << endl << "GO " <<Cname<< '!'<<" \n\nLeave this place and never return." <<endl << endl << "Press any key to get out of my sight." << endl;
	cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	menuControl = 9;
	return 0;
}

void hangman::playhangman(int& successfulCompletions, string& Cname)
{

//coded by Luke Martin
//Picks a word from the file of 30 words, shows the user  _'s, they input a guess.
//If correct reveal from the _'s where, then guess again,
//Once all are reavealed user wins, if user runs out of "lives" game is lost

	//variables
	system("cls");
	const int SIZE = 30;
	int i = 0;
	const int MAX_TRIES = 5;
	char letter{};
	int wrong_guess = 0;
	string guesses;
	string word;
	string words[SIZE];										//+1 one dimensional array
	fstream hangmanwords;									//+1 input file
	//open file to obatin words
	hangmanwords.open("words.txt");
	//if else for error checking
	if (hangmanwords.fail())								//if statement
	{
		cout << "words.txt failed to open, please check the file." << endl << "Press any key to return to trial selection.";
		system("pause>null");
	}
	else
	{
		while (!hangmanwords.eof() && i < SIZE)				//+1 While loop & checks  for EOF
		{
			getline(hangmanwords, words[i]);
			++i;
		}
	}
	//close the file
	hangmanwords.close();//file close
//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n = rand() % 30;
	word = words[n];

	//sets word to be hidden by underscores
	string unknown(word.length(), '_');
	//while loop for program execution		
	while (wrong_guess < MAX_TRIES)							//+1 While Loop
	{
		//outputs heading with color
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "***********************************************************************************************************************";
		cout << "\nWelcome " << Cname << " to a trial of words, Your only hint is that all apply to C++";
		cout << "\n\nEach letter is represented by an underscore, your goal, to unveil the word before your guesses run out!";
		cout << "\n\nWe suggest one letter a time, but you may enter more if you want! \nIf you attempt to enter a letter you ahve already guessed, you will be prompted for a new input.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		if (MAX_TRIES - wrong_guess == 1)						//If statement
		{
			cout << "\n\nYou have " << MAX_TRIES - wrong_guess << " incorrect guess remaining to attempt to guess the word.";
		}//end if
		else
		{
			cout << "\n\nYou have " << MAX_TRIES - wrong_guess << " incorrect guesses remaining to attempt to guess the word.";
		}//end else

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		cout << "\n***********************************************************************************************************************";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		//displays the hidden word/whatever revealed letters each time
		cout << "\nThese are your guesses in alphabetical order: ";
		for (int j = 0; j < guesses.size(); j++)		//outputs the letters user guesses in alphabetical order with comma separating. 
		{
			cout << guesses[j];
			cout << ", ";
		
		}

		cout << "\n\n" << unknown;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		//users guess
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		//compares the input against the string of guesses to determine if the new guesses is already present or not
		wordManip(letter, guesses);

		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown) == 0)				//If statement
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << endl << "HAH! That is wrong!" << endl;
			wrong_guess++;
		}//end if
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "\nA correct input.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			if (word != unknown)								//If statement
			{
				cout << "\n\n" << unknown << endl << endl;
			}//end if
		}//end else

		// Tell user how many guesses are left/ ends the game if out of lives or word is found
		//specific wording for 1 remaining
		//winning scenario
		if (word == unknown)									//If statement
		{
			incrementCompletions(successfulCompletions);
			hangmanCompleted = TRUE;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "\n\nYou have correctly unveiled: " << word << endl;
			cout << "As a result, you have earned my completion plaque!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			cout << "\n\nMake an input to return to the menu";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			break;
			
		}//end if
		//losing scenario
		else if (wrong_guess == MAX_TRIES)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "You have run out of guesses.";
			cout << "\nAs such you have failed this time; at the Gatehouse you may choose to comeback, or undertake another trial." << endl;
			cout << "The word was: " << word << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			cout << "\n\nMake an input to return to the menu";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		}//end else if
		//specific wording for 1 remaining
		else if (MAX_TRIES - wrong_guess == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "\nYou have " << MAX_TRIES - wrong_guess;
			cout << " guess left." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			cout << "Press a key to guess again." << endl;
			system("pause>null");
			system("cls");
		}//end else if
		//any other scenario
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "You have " << MAX_TRIES - wrong_guess;
			cout << " guesses left." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			cout << "Press a key to guess again.";
			system("pause>null");
			system("cls");
		}//end else
	}

	cin.ignore();
	cin.get();
}
int hangman::letterFill(char guess, string secretword, string& guessword)
{
	//variables
	//coded by Luke Martin
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++)									//+1 For Loop
	{
		// Checks if letter already exists
		if (guess == guessword[i])
			return 0;
		//end if
		// Checks if letter is in the word
		if (guess == secretword[i])								
		{
			guessword[i] = guess;							    //+1 string operation
			matches++;
		}//end if
	}//end for
	return matches;
}

void hangman::wordManip(char& letter, string& guesses)
{
	//coded by: Luke Martin
	//compares the char input against the string that contains all of the previous guesses.
	//utilizes a do while in order to allow for multiple duplicate inputs in a row.
	for (int k = 0; k < guesses.size(); k++)
	{

		if (letter == guesses[k])					//if checks for equality
		{
			do
			{
				cout << "\nYou have already guessed this letter! Please enter a unique input: ";
				cin >> letter;
			} while (letter == guesses[k]);			//do while exit condition                   +do-while
		}

	}
	if (isupper(letter)) letter = tolower(letter);  //lets capitals be correct answers
	guesses.push_back(letter);						//adds guesses to the end of the string		+string operation			
	sort(guesses.begin(), guesses.end());			//sorts alphabetically						+string operation
}


void displaygarrettsSegment() {

	//coded by: Garrett Wolak
	//Function that contains Garrett's Story Segment.
	//Includes progressive dialog that user manually clicks through in order to keep reading.
	
	cout << endl;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);

	cout << "You continue down the road for some time before you come across a gang of bandits." << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << "You decide to approach them as they are in your way and you need to pass to continue your journey." << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << "As you approach, the presumptive leader of the bandits begins to walk towards you with a menacing look on his face." << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << '"' << "Who are you?" << '"' << " the bandit asks." << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << "Afraid to upset the big hairy beast of a man, you tell him. " << '"' << "My name is " << Cname << '.' << '"' << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << '"' << "Well hello there " << Cname << '.' << '"' << " the bandit says. " << '"' << "If you want to pass, your gonna have to play a game hehe." << '"' << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << "Since it appears you have no choice, and there are far too many bandits for you to take on by yourself, you decide to take the man up on his offer." << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << '"' << "What kind of game?" << '"' << " you ask. " << '"' << "It's really straight forward" << '"' << " the man states. " << endl << endl; 

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << '"' << "All you have to do is roll this six sided die. If you roll an even number, you get to pass unscathed." << '"' << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << '"' << "On the other hand, if you are unfortunate enough to roll an odd number, your journey ends here hehe." << '"' << endl << endl;

	SetConsoleTextAttribute(h, 3);
	system("pause");
	cout << endl;
	SetConsoleTextAttribute(h, 2);

	cout << "Confident you will be able to beat the odds, you roll the die." << endl << endl;

	SetConsoleTextAttribute(h, 3);
	cout << "Press any key to roll the die . . .";
	system("pause>nul");
	cout << endl << endl;

	rollDie(); // Function to roll the die and continue the story.

}

void rollDie() {

	//coded by: Garrett Wolak
	// Function to roll a six sided die.
	//If the user rolls an even number, their story continues onto Kendras Story Segment
	//If the user rolls an odd number, they lose the game but can easily re-roll to eventually move on in the story without completely restarting.
	
rollDie:

	int dieResult;
	
	//Loop to roll a simulated six sided die. 
	srand(time(0));
	for (int i = 0; i < 1; i++)
	{
		dieResult = (int)(1 + rand() % 6);

	}

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);

	cout << "You rolled a: " << dieResult << endl;

	//Decides if the user won or lost and if they need to re-roll in order to progress.
	if (dieResult == 2 || dieResult == 4 || dieResult == 6) {

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);

		cout << "Congratulations! You Won! Your Journey Continues!" << endl << endl;

		SetConsoleTextAttribute(h, 2);

		cout << "You rolled a " << dieResult << " so the bandits honored there promise and let you pass unharmed." << endl << endl;

		SetConsoleTextAttribute(h, 3);
		system("pause");
		cout << endl;
		SetConsoleTextAttribute(h, 2);

		cout << "You journey now continues as you once again head down the long road." << endl << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "End of Garrett's Story Segment"; // End of Garrett's Story Segment
		system("pause>nul");
		cout << endl << endl;

	}
	else {

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);

		cout << "Sorry you Lose. :( " << endl << endl;

		SetConsoleTextAttribute(h, 2);

		cout << "You rolled a " << dieResult << " so the bandits demolished you and took all of your belongings." << endl << endl;

		SetConsoleTextAttribute(h, 3);
		cout << "Press any key to try rolling again . . .";
		system("pause>nul");
		cout << endl << endl;

		goto rollDie; // So the user can try again and re-roll the die 

	}

}

