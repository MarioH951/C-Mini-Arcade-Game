// Mario Hernandez
// CIS5-Online
// 2-5-2025
// Final Project: Option A


#include <iostream>
#include <iomanip>
#include <string>
#include <ctime> 
#include <cstdlib> 

using namespace std;

// Function prototypes
int displayMainMenu(string& name); 
int displayMenuTutor();
void mathTutor(string name);
void rockPaperScissors(string name);
int computerChoice(int min, int max);
int playerChoice(int num1, int num2, int num3);
void calculateWinner(int computerChoice, int playerChoice, int& totalTies, int& totalWins, int& totalLoses);
void ShowResults(int& totalTies, int& totalWins, int& totalLoses);
bool isValidTutor(int num, int min, int max);


bool addition(int& totalAttempts, int& attemptsRight, int& attemptsWrong);
bool subtraction(int& totalAttempts, int& attemptsRight, int& attemptsWrong);
bool multiplication(int& totalAttempts, int& attemptsRight, int& attemptsWrong);
bool division(int& totalAttempts, int& attemptsRight, int& attemptsWrong);

void showStats(int& totalAttempts, int& attemptsRight, int& attemptsWrong);

int main()
{
    string name;
    int seed = time(0);
    srand(seed);

    int mainChoice;

    do
    {
        mainChoice = displayMainMenu(name);	//Displays menu

        switch (mainChoice)
        {
        case 1:
            mathTutor(name);	//Displays math tutor
            break;

        case 2:
            rockPaperScissors(name);	//Displays RPS game
            break;

        case 3:		//Exits the program
            cout << "You are now leaving the program." << endl;
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
        }
    } while (mainChoice != 3);

    return 0; 
}

//========================================================================================
int displayMainMenu(string& name) 
{
    //Prompts user to choose math tutor or RPS

    int mainChoice; 

    cout << "What's your name? "; 
    getline(cin, name);

    cout << "Welcome " << name << "!" << endl; 


    cout << "Choose a game " << endl
        << "--------------------------------------------------------" << endl
        << "1. Math Tutor \n"
        << "2. Rock Paper Scissors \n"
        << "3. Exit \n";

    cin >> mainChoice;
    cin.ignore(99, '\n');

    return mainChoice;
}
//========================================================================================
void rockPaperScissors(string name)
{
    //Main function for RPS

    int num1 = 1, num2 = 2, num3 = 3;
    int min = 1, max = 3;
    int computerPick;
    string computerSelect;
    int playerPick;
    int totalTies = 0, totalWins = 0, totalLoses = 0;
    char userInput;

    cout << "Welcome to Rock Paper Scissors, " << name << "!" << endl;

    
    do {
        computerPick = computerChoice(min, max);	//Gets computers response and asssigns R P or S to it
        if (computerPick == 1)
            computerSelect = "Rock";
        else if (computerPick == 2)
            computerSelect = "Paper";
        else
            computerSelect = "Scissors";

        playerPick = playerChoice(num1, num2, num3);	//Gets players response

        // Validate playerPick before proceeding
        if (playerPick >= 1 && playerPick <= 3) {
            cout << "The computer chose " << computerSelect << "." << endl; //Displays computers response
            calculateWinner(computerPick, playerPick, totalTies, totalWins, totalLoses);	//Displays the winner
            ShowResults(totalTies, totalWins, totalLoses);	//Shows results 
        }
        else {
            cout << "Invalid player choice. Please enter 1, 2, or 3." << endl;
        }

        cout << "Do you want to play again? (y/n) ";
        cin >> userInput;
        cin.ignore(99, '\n');
    } while (userInput == 'y' || userInput == 'Y');

    cout << "Thanks for playing Rock Paper Scissors!" << endl << endl;
}
//========================================================================================
int computerChoice(int min, int max)
{
    int computerChoiceNum; 

    computerChoiceNum = min + (rand() % (max - min + 1));	

    return computerChoiceNum;
}
//========================================================================================
int playerChoice(int num1, int num2, int num3)
{
    int playerSelection; 

    cout << "Choose rock, paper, or scissors:" << endl
        << "--------------------------------------------------------" << endl
        << "1. Rock \n"
        << "2. Paper \n"
        << "3. Scissors \n";
    cin >> playerSelection;
    cin.ignore(99, '\n');

    // Return playerSelection directly after validation
    if (playerSelection >= 1 && playerSelection <= 3) {
        return playerSelection;
    }
    else {
        cout << "Invalid input. Please try again." << endl;
        return 0; // Indicates an invalid choice
    }
}
//========================================================================================
void calculateWinner(int computerChoice, int playerChoice, int& totalTies, int& totalWins, int& totalLoses)
{
   
    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
        totalTies++;
    }
    else if (
        (playerChoice == 1 && computerChoice == 3) || // Rock vs Scissors
        (playerChoice == 2 && computerChoice == 1) || // Paper vs Rock
        (playerChoice == 3 && computerChoice == 2)    // Scissors vs Paper
        ) {
        cout << "Player wins!" << endl;
        totalWins++;
    }
    else {
        cout << "Computer wins!" << endl;
        totalLoses++;
    }
}
//========================================================================================
void ShowResults(int& totalTies, int& totalWins, int& totalLoses)
{
    cout << "You tied a total of " << totalTies << " times." << endl;
    cout << "You won a total of " << totalWins << " times." << endl;
    cout << "You lost a total of " << totalLoses << " times." << endl << endl;
}
//========================================================================================
void mathTutor(string name)
{
    //main function for math tutor 

    int choice;
    int totalAttempts = 0, attemptsRight = 0, attemptsWrong = 0;
    bool continuePlayingCurrentMath = true; 

    cout << "Welcome to Math Tutor, " << name << "!" << endl;

    do
    {
        choice = displayMenuTutor();

        switch (choice)
        {
        case 1: //add
            continuePlayingCurrentMath = addition(totalAttempts, attemptsRight, attemptsWrong);
            break;

        case 2: ///sub
            continuePlayingCurrentMath = subtraction(totalAttempts, attemptsRight, attemptsWrong);
            break;
        case 3: //mul
            continuePlayingCurrentMath = multiplication(totalAttempts, attemptsRight, attemptsWrong);
            break;
        case 4:	//div
            continuePlayingCurrentMath = division(totalAttempts, attemptsRight, attemptsWrong);
            break;
        case 5: // Quit from Math Tutor
            cout << endl << "Exiting Math Tutor." << endl << endl;
            break; // Exit the loop
        default:
            cout << "An error occurred. Invalid input. " << endl << endl;
        }
        
    } while (choice != 5);

    cout << "Thank you for using Math Tutor!" << endl << endl;
}
//========================================================================================
int displayMenuTutor()
{
    int c;

    cout << "Choose a selection " << endl
        << "--------------------------------------------------------" << endl
        << "1. Addition \n"
        << "2. Subtraction \n"
        << "3. Multiplication \n"
        << "4. Division \n"
        << "5. Quit \n";

    cin >> c;
    cin.ignore(99, '\n');

   
    while (!isValidTutor(c, 1, 5))	//Checks that user's selection is either 1-5
    {
        cin >> c;
        cin.ignore(99, '\n');
    }

    return c;
}
//========================================================================================
bool isValidTutor(int num, int min, int max)
{
    if (num < min || num > max)	//Validates user's response and prompts them to choose another selection if wrong
    {
        cout << "Invalid selection." << endl << endl; 
        cout << "Please choose a selection:\n"
            << "--------------------------------------------------------" << endl
            << "1. Addition \n"
            << "2. Subtraction \n"
            << "3. Multiplication \n"
            << "4. Division \n"
            << "5. Quit \n";

        return false;
    }
    else
        return true;
}
//========================================================================================

bool addition(int& totalAttempts, int& attemptsRight, int& attemptsWrong)
{
    int num1, num2, min, max, answer, result;
    int attempts; 
    char userInput;
    bool playAgain = true; 

    do {
        attempts = 2; // Reset attempts for each new problem

        //assigns random number to num1 and num2 that matchaes parameters
        min = 2, max = 500;
        num1 = min + (rand() % (max - min + 1));

        min = 1, max = 99;
        num2 = min + (rand() % (max - min + 1));


        result = num1 + num2;

        //displays math problem
        cout << "Addition: You have 3 attempts " << endl;
        cout << setw(5) << num1 << endl
            << "+ " << num2 << endl
            << "_____\n";
        cin >> answer;
        cin.ignore(99, '\n');

        //Displays message when answer is wrong 
        while (answer != result && attempts > 0)
        {
            cout << "Sorry that's incorrect. \n";
            cout << attempts << " attempts remaining. \n";
            cout << setw(5) << num1 << endl
                << "+ " << num2 << endl
                << "_____\n";
            cin >> answer;
            cin.ignore(99, '\n');
            attempts--;
        }
        //displays outcome and either increases attemptsRight or attempts wrong
        if (answer == result)
        {
            cout << "Congratulations!\n";
            attemptsRight++;
        }
        else
        {
            cout << "Sorry the answer is " << result << endl;
            attemptsWrong++;
        }
        //finds the total attempts and displays them
        totalAttempts = attemptsRight + attemptsWrong;
        showStats(totalAttempts, attemptsRight, attemptsWrong);

        //resets attempts if the user does not want to continue playing 
        cout << "Do you want to play another addition problem? (y/n) ";
        cin >> userInput;
        cin.ignore(99, '\n');
        if (userInput == 'n' || userInput == 'N') {
            playAgain = false; // User does not want to continue this specific math operation
            totalAttempts = 0; attemptsWrong = 0; attemptsRight = 0; // Reset stats
        }
    } while (playAgain); // Loop continues as long as user wants to play addition problems

    return playAgain;
}
//========================================================================================
bool subtraction(int& totalAttempts, int& attemptsRight, int& attemptsWrong)
{

    int num1, num2, min, max, answer, result;
    int attempts; // Removed initialization, will be set in loop
    char userInput;
    bool playAgain = true;

    do {
        attempts = 2; // Reset attempts for each new problem

        //assigns random number to num1 and num2 that matchaes parameters
        min = 2, max = 500;
        num1 = min + (rand() % (max - min + 1));

        min = 1, max = 500;
        num2 = min + (rand() % (max - min + 1));
        //asssigns new value to num2 if its bigger than num1
        while (num2 >= num1)
            num2 = min + (rand() % (max - min + 1));

        result = num1 - num2;

        //displayer subtraction problem
        cout << "Subtraction: You have 3 attempts " << endl;
        cout << setw(3) << num1 << endl
            << "- " << num2 << endl
            << "_____\n";
        cin >> answer;
        cin.ignore(99, '\n');

        //displays message when its wrong 
        while (answer != result && attempts > 0)
        {
            cout << "Sorry that's incorrect. \n";
            cout << attempts << " attempts remaining. \n";
            cout << setw(3) << num1 << endl
                << "- " << num2 << endl
                << "_____\n";
            cin >> answer;
            cin.ignore(99, '\n');
            attempts--;
        }

        //Displays outcome and either increases attemptsRight or attempts wrong
        if (answer == result)
        {
            cout << "Congratulations!\n";
            attemptsRight++;
        }
        else
        {
            cout << "Sorry the answer is " << result << endl;
            attemptsWrong++;
        }

        //find total attempts and displays the stats
        totalAttempts = attemptsRight + attemptsWrong;
        showStats(totalAttempts, attemptsRight, attemptsWrong);

        //resets the attempts if user does not does want to play again
        cout << "Do you want to play another subtraction problem? (y/n) ";
        cin >> userInput;
        cin.ignore(99, '\n');
        if (userInput == 'n' || userInput == 'N') {
            playAgain = false;
            totalAttempts = 0; attemptsWrong = 0; attemptsRight = 0; // Reset stats
        }
    } while (playAgain);

    return playAgain;
}
//========================================================================================
bool multiplication(int& totalAttempts, int& attemptsRight, int& attemptsWrong)
{
    int num1, num2, min, max, answer, result;
    int attempts; 
    char userInput;
    bool playAgain = true;

    do {
        attempts = 2; // Reset attempts for each new problem

        //assigns a random number to num1 and num2
        min = 1, max = 12;
        num1 = min + (rand() % (max - min + 1));

        min = 1, max = 12;
        num2 = min + (rand() % (max - min + 1));


        result = num1 * num2;

        //displays math problem
        cout << "Multiplication: You have 3 attempts " << endl;
        cout << setw(4) << num1 << endl
            << "* " << num2 << endl // Corrected spacing
            << "_____\n";
        cin >> answer;
        cin.ignore(99, '\n');

        //displays error message if its wrong 
        while (answer != result && attempts > 0)
        {
            cout << "Sorry that's incorrect. \n";
            cout << attempts << " attempts remaining. \n";
            cout << setw(4) << num1 << endl
                << "* " << num2 << endl 
                << "_____\n";
            cin >> answer;
            cin.ignore(99, '\n');
            attempts--;
        }

        //displays the right answer and either increases attempts right or attempts wrong
        if (answer == result)
        {
            cout << "Congratulations!\n";
            attemptsRight++;
        }
        else
        {
            cout << "Sorry the answer is " << result << endl;
            attemptsWrong++;
        }

        //find the total number of attempts
        totalAttempts = attemptsRight + attemptsWrong;
        showStats(totalAttempts, attemptsRight, attemptsWrong);

        //resets the attempts if the user selects no
        cout << "Do you want to play another multiplication problem? (y/n) ";
        cin >> userInput;
        cin.ignore(99, '\n');
        if (userInput == 'n' || userInput == 'N') {
            playAgain = false;
            totalAttempts = 0; attemptsWrong = 0; attemptsRight = 0; // Reset stats
        }
    } while (playAgain);

    return playAgain;
}
//========================================================================================
bool division(int& totalAttempts, int& attemptsRight, int& attemptsWrong)
{
    int num1, num2, min, max, answer, result;
    int attempts; 
    char userInput;
    bool playAgain = true;

    do {
        attempts = 2; // Reset attempts for each new problem

        //assigns a random number to num1 and num2
        min = 10, max = 99;
        num1 = min + (rand() % (max - min + 1));

        min = 1, max = 9;
        num2 = min + (rand() % (max - min + 1));

        //assigns a new number to num2 if its greater than num1
        while (num2 >= num1 || num1 % num2 != 0) { // Added num1 % num2 != 0
            num1 = min + (rand() % (max - min + 1));
            num2 = min + (rand() % (max - min + 1));
        }

        result = num1 / num2;

        //displays division problem
        cout << "Division: You have 3 attempts " << endl; 
        cout << setw(4) << num1 << endl
            << "/ " << num2 << endl 
            << "_____\n";
        cin >> answer;
        cin.ignore(99, '\n');

        //displays error message if answer is incorrect
        while (answer != result && attempts > 0)
        {
            cout << "Sorry that's incorrect. \n";
            cout << attempts << " attempts remaining. \n";
            cout << setw(4) << num1 << endl
                << "/ " << num2 << endl
                << "_____\n";
            cin >> answer;
            cin.ignore(99, '\n');
            attempts--;
        }

        //displays correct answer and either increase attemptsRight or attemptsWrong
        if (answer == result)
        {
            cout << "Congratulations!\n";
            attemptsRight++;
        }
        else
        {
            cout << "Sorry the answer is " << result << endl;
            attemptsWrong++;
        }

        //find total number of attempts
        totalAttempts = attemptsRight + attemptsWrong;
        showStats(totalAttempts, attemptsRight, attemptsWrong);

        //resets number attempts if user selects no
        cout << "Do you want to play another division problem? (y/n) ";
        cin >> userInput;
        cin.ignore(99, '\n');
        if (userInput == 'n' || userInput == 'N') {
            playAgain = false;
            totalAttempts = 0; attemptsWrong = 0; attemptsRight = 0; // Reset stats
        }
    } while (playAgain);

    return playAgain;
}
//========================================================================================
void showStats(int& totalAttempts, int& attemptsRight, int& attemptsWrong)
{
    //displays the stats
    cout << "The total amount of problems that you've attempted is " << totalAttempts << "." << endl; // Added period
    cout << "The amount of problems you've gotten right is " << attemptsRight << "." << endl; // Added period
    cout << "The amount of problems you've gotten wrong is " << attemptsWrong << "." << endl << endl; // Added period
}