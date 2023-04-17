#include <iostream>
#include <windows.h>
#include <conio.h> //Used for input without enter
#include <stdlib.h> // EXIT FUNC

using namespace std;

bool inMain = true; // Declare variables used for knowing if user is in the main menu
bool inShop = false; // Declare variable used for knowing if user is in the shop menu
bool alive = true; // Declare variable used for knowing if pet is alive


int main() {
	//Variables
	int happiness = 100; //Declare variable
	int hunger = 0; //Declare variable
	int tiredness = 0; //Declare variable
	int fat = 0; //Declare variable
	int laziness = 0; //Declare variable
	int dirtiness = 0; // Declare variables used for stats
	string name = "Your pet"; // Declare variable
	string food = " "; // Declare variable
	char nameChoice = ' '; // Declare variable used for options
	char menuChoice = ' '; // Declare variables used for menus
	int gold = 50; // Declare variable
	int hamburgerCount = 1; // Declare variables
	int	saladCount = 1; // Declare variables
	int	steakCount = 1; // Declare variables

	//Function prototypes
	void feedPet(int&, int&, int&, string&, int&, int&, int&, string&, int&); //Function prototype
	void napPet(int&, int&, int&, string&, int&); //Function prototype
	void mainMenu(string, int&, int, int&, int&, int&, int&); //Function prototype
	void shopMenu(int&, int&, int&, int&); //Function prototype
	void clear(); //Function prototype
	char menuSelect(string, char&); //Function prototype
	void currentState(int&, int&, int&, int&, int&, string); //Function prototype
	void goWork(string, int&, int&, int&, int&, int&, int&); //Function prototype
	void takeShower(int&, int&, int&); //Function prototype
	void hamburger(int&, int&, int&); //Function prototype
	void salad(int&, int&, int&); //Function prototype
	void steak(int&, int&, int&); //Function prototype
	
	while (nameChoice != 'Y' && nameChoice != 'N' && nameChoice != 'y' && nameChoice != 'n') { // While loop runs until user give a correct input
		cout << "Press Y if you want to name your pet or N if you do not want to: " << endl; // Displays message
		nameChoice = _getch(); //Gets user input without the user needing to press ENTER

		if (nameChoice == 'Y' || nameChoice == 'y') { //If statetement checks if correct button is pressed
			cout << "Enter a name for your pet: "; //Displays message
			cin >> name; //Accepts user input
			cout << endl;
			cout << "Your pet will be named " << name << endl; //Displays message
		}
		else if (nameChoice == 'N' || nameChoice == 'n') { //If statetement checks if correct button is pressed
			cout << "You choose to not name your pet." << endl; //Displays message
		}
		else { // Else statement if user tries to input something else
			cout << "Incorrect input" << endl; //Displays message
		}

	}

	clear(); //Function call for a function which clears the terminal
	mainMenu(name, gold, 0, hamburgerCount, saladCount, steakCount, happiness); //Function call for main menu function
	currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Function call for the stats displaying function

	while ((menuChoice != 'Q' && menuChoice != 'q') && alive == true) { // While loop runs until user give a correct input
		menuChoice = _getch(); //Gets user input without the user needing to press ENTER
		if (menuChoice == 'F' || menuChoice == 'f') { //If statetement checks which button is pressed
			feedPet(hunger, fat, tiredness, food, hamburgerCount, saladCount, steakCount, name, happiness); //Runs the feedPet function
			system("pause"); //Pauses until user presses enter
			clear(); //Function call for a function which clears the terminal
			mainMenu(name, gold, 0, hamburgerCount, saladCount, steakCount, happiness); //Function call for main menu function. Runs it again to display after clear.
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Function call for the stats displaying function. Runs it again to update stats.
		}
		else if (menuChoice == 'N' || menuChoice == 'n') { //Else if statetement checks which button is pressed
			napPet(tiredness, laziness, hunger, name, happiness);//Function call for the pet nap function
			system("pause"); //Pauses until user presses enter
			clear(); //Function call for a function which clears the terminal
			mainMenu(name, gold, 0, hamburgerCount, saladCount, steakCount, happiness); //Function call for main menu function. Runs it again to display after clear.
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Function call for the stats displaying function. Runs it again to update stats.
		}
		else if (menuChoice == 'S' || menuChoice == 's') { //Else if statetement checks which button is pressed
			cout << name << " took a shower." << endl; //Displays message
			system("pause"); //Pauses until user presses enter
			takeShower(tiredness, dirtiness, happiness); //Function call for the shower function
			clear(); //Function call for a function which clears the terminal
			mainMenu(name, gold, 0, hamburgerCount, saladCount, steakCount, happiness); //Function call for main menu function. Runs it again to display after clear.
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Function call for the stats displaying function. Runs it again to update stats.
		}
		else if (inMain == true && (menuChoice == 'B' || menuChoice == 'b')) { //Else if statetement checks which button is pressed and if used is in the main menu
			clear(); //Function call for a function which clears the terminal
			shopMenu(gold, hamburgerCount, saladCount, steakCount); //Function call for a function which enters the shop menu
		}
		else if (inShop == true && (menuChoice == 'B' || menuChoice == 'b')) { //Else if statetement checks which button is pressed and if user is in the shop
			clear(); //Function call for a function which clears the terminal
			mainMenu(name, gold, 0, hamburgerCount, saladCount, steakCount, happiness); //Function call for main menu function. Runs it again to display after clear.
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Function call for the stats displaying function. Runs it again to update stats.
		}
		else if (menuChoice == 'W' || menuChoice == 'w') { //Else if statetement checks which button is pressed
			goWork(name, gold, tiredness, hunger, laziness, dirtiness, happiness); //Function call for a function for the work function.
			system("pause"); //Pauses until user presses enter
			clear(); //Function call for a function which clears the terminal
			mainMenu(name, gold, 0, hamburgerCount, saladCount, steakCount, happiness); //Function call for main menu function. Runs it again to display after clear.
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Function call for the stats displaying function. Runs it again to update stats.
		}
		else if (inShop == true && menuChoice == '1' && gold >= 10) { //Else if statetement checks which button is pressed and if user has enough money to buy item
			cout << "You bought a hamburger (-10 gold)" << endl; //Displays message
			gold -= 10;
			hamburgerCount++; //Adds 1 to he hamburger count
			system("pause"); //Pauses until user presses enter
			clear(); //Function call for a function which clears the terminal
			shopMenu(gold, hamburgerCount, saladCount, steakCount); //Runs shop menu again to update coutn of hamburgers
		}
		else if (inShop == true && menuChoice == '2' && gold >= 15) { //Else if statetement checks which button is pressed and if user has enough money to buy item
			cout << "You bought a salad (-15 gold)" << endl; //Displays message
			gold -= 15;
			saladCount++; //Adds 1 to he salad count
			system("pause"); //Pauses until user presses enter
			clear(); //Function call for a function which clears the terminal
			shopMenu(gold, hamburgerCount, saladCount, steakCount); //Runs shop menu again to update coutn of salads
		}
		else if (inShop == true && menuChoice == '3' && gold >= 20) { //Else if statetement checks which button is pressed and if user has enough money to buy item
			cout << "You bought a steak (-20 gold)" << endl; //Displays message
			gold -= 20;
			steakCount++; //Adds 1 to he steak count
			system("pause"); //Pauses until user presses enter
			clear(); //Function call for a function which clears the terminal
			shopMenu(gold, hamburgerCount, saladCount, steakCount); //Runs shop menu again to update count of steaks
		}
		else if (inShop == true && (menuChoice == '1' || menuChoice == '2' || menuChoice == '3')) { //Else if statement runs if user has no money to buy food
			switch (menuChoice) { //Swtich satement which checks what the user input was
				case '1':
					cout << "Not enough gold to purchase hamburger" << endl; //Displays message
					system("pause"); //Pauses until user presses enter
					clear(); //Function call for a function which clears the terminal
					shopMenu(gold, hamburgerCount, saladCount, steakCount); //Display shop menu again to update
					break;
				case '2':
					cout << "Not enough gold to purchase salad" << endl; //Displays message
					system("pause"); //Pauses until user presses enter
					clear();//Function call for a function which clears the terminal
					shopMenu(gold, hamburgerCount, saladCount, steakCount); //Display shop menu again to update
					break;
				case '3':
					cout << "Not enough gold to purchase steak" << endl; //Displays message
					system("pause"); //Pauses until user presses enter
					clear();//Function call for a function which clears the terminal
					shopMenu(gold, hamburgerCount, saladCount, steakCount); //Display shop menu again to update
					break;
			}
		}
		else if (inMain == true  && menuChoice == '1') { //else if statement used for the food selection in main menu
			clear(); //Function call for a function which clears the terminal
			mainMenu(name, gold, 1, hamburgerCount, saladCount, steakCount, happiness); //Display main menu again to after clear
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Display stats again after clear
			food = "hamburger";
		}
		else if (inMain == true && menuChoice == '2') { //else if statement used for the food selection in main menu
			clear();
			mainMenu(name, gold, 2, hamburgerCount, saladCount, steakCount, happiness); //Display main menu again to after clear
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Display stats again after clear
			food = "salad";
		}
		else if (inMain == true && menuChoice == '3') { //else if statement used for the food selection in main menu
			clear();
			mainMenu(name, gold, 3, hamburgerCount, saladCount, steakCount, happiness); //Display main menu again to after clear
			currentState(hunger, tiredness, fat, laziness, dirtiness, name); //Display stats again after clear
			food = "steak";
		}
	}


	return 0;
}


// Hamburger function containing stats
void hamburger(int& hungerLevel, int& fatLevel, int& happyLevel) { 
	hungerLevel -= 2;
	fatLevel += 2;
	if (hungerLevel < 0) {
		hungerLevel = 0;
		happyLevel -= 10; //Happiness gets decresed by 10 cause pet gain 2 fat
	}
}

// Salad function containing stats
void salad (int& hungerLevel, int& fatLevel, int& happyLevel) {
	hungerLevel -= 1; //Decrease hunger
	fatLevel -= 1; //Decrease fat
	happyLevel += 10; //Increase happiness
	if (hungerLevel < 0) {
		hungerLevel = 0; //reset hunger
		happyLevel += 5; //Increase happiness
	}
	else if (fatLevel < 0) {
		fatLevel = 0; //Reset fat
		happyLevel += 5; //Increase happiness
	}
}

//Steak function containing stats
void steak(int& hungerLevel, int& fatLevel, int& happyLevel) {
	hungerLevel -= 3; //Decrease hunger
	fatLevel += 1; //Increase fat
	happyLevel += 10; //Increase happiness
	if (hungerLevel < 0) {
		hungerLevel = 0; //Reset hunger
		happyLevel += 5; //Increase happiness
	}
}

//Function which makes the character go eat and increases and decreases the appropriate stats
void feedPet(int& hungerLevel, int& fatLevel, int& tiredLevel, string& foodChoice, int& hamburgerInventory, int& saladInventory, int& steakInventory, string& name, int& happyLevel) {
	void hamburger(int&, int&, int&); //function prototypes
	void salad(int&, int&, int&);  //function prototypes
	void steak(int&, int&, int&); //function prototypes

	tiredLevel++; //Increasese tiredness
	happyLevel -= 5; //Decreases happiness

	if (foodChoice == "hamburger" && hamburgerInventory >= 1) { //If statement checks what food is selected
		hamburger(hungerLevel, fatLevel, happyLevel); //Function call
		hamburgerInventory--; //Reduce inventory
	}
	else if (foodChoice == "salad" && saladInventory >= 1) { //If statement checks what food is selected
		salad(hungerLevel, fatLevel, happyLevel);  //Function call
		saladInventory--; //Reduce inventory
	}
	else if (foodChoice == "steak" && steakInventory >= 1) { //If statement checks what food is selected
		steak(hungerLevel, fatLevel, happyLevel);  //Function call
		steakInventory--; //Reduce inventory
	}
	else if ((foodChoice == "hamburger" || foodChoice == "salad" || foodChoice == "steak") && (hamburgerInventory == 0 || saladInventory == 0 || steakInventory == 0)) { //Else if statement checks if food has ran out
		cout << "You don't have any of that food left" << endl; //Displays message
	}
	else {
		cout << "No food is selected. Use 1, 2 and 3 to choose between hamburger, salad or steak." << endl; //Displays message
	}


	if (hungerLevel == 0) { //Checks if full
		cout << endl;
		cout << name << " is not hungry. It's hunger is now " << hungerLevel << "/4" << endl; //Displays message
	}	
	else if (hungerLevel >= 1) { //Checks if hungry
		cout << endl;
		cout << name << " ate. It's hunger is now " << hungerLevel << "/4" << endl;  //Displays message
	}
	else if (fatLevel >= 1) {  //Checks if overeating
		cout << endl;
		cout << name << " is overeating and will start becoming fat" << hungerLevel << "/4" << endl;  //Displays message
	}

}

//Function which makes the character go nap and increases and decreases the appropriate stats
void napPet(int& tiredLevel, int& lazyLevel, int& hungerLevel, string& name, int& happyLevel) {

	hungerLevel++; //Increase hunger

	if (tiredLevel == 0) {
		cout << endl;
		cout << name <<" is not tired. It's tired level is " << tiredLevel << "/4" << endl;
		lazyLevel++; //Increase laziness
		happyLevel -= 10; // Hunger increase + lazy increase
	}
	else if (tiredLevel >= 1) {
		tiredLevel -= 2;
		happyLevel += 10; //Increase happiness
		if (tiredLevel < 0) {
			tiredLevel = 0; //Reset tiredness
			happyLevel -= 5; //Hunger icrease
		}
		cout << endl;
		cout << name << " took a nap. It's tired level is now " << tiredLevel << "/4" << endl; //Displays message
	}
	else if (lazyLevel >= 1) {
		cout << endl;
		happyLevel -= 5; //Decrease happiness
		cout << name << " took a nap even though it is not tired. It will start becoming lazy" << endl; //Displays message
	}


}

//Function which displays the stats of the character on the screen
void currentState(int& hungerState, int& tiredState, int& fatState, int& lazyState, int& dirtyState, string name) {
	void clear(); //function prototype
	void gameOver(string); //function prototype
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //Used for changing text colour

	if (hungerState >= 4) { //Checks if hunger is above threshhold
		cout << name << " is dead from hunger. It's hunger is " << hungerState << "/4" << endl; //DIsplays message
		cout << "Food bar:     "; //DIsplays message
		SetConsoleTextAttribute(color, 4); //Changes text colour to red
		cout << "////////////////////////////////////////" << endl; //DIsplays message
		SetConsoleTextAttribute(color, 7); //Changes text colour back to white
		gameOver(name); //Function call for the gameOver function which displays game over message
		alive = false; //Sets alive to false ending while loop in main() and quitting
	}
	else if (tiredState >= 4) { //Checks if tiredness is above threshhold
		cout << name << " has collapsed and died. It's energy is " << tiredState << "/4" << endl; /// Displays message
		cout << "Energy bar:   "; //DIsplays message
		SetConsoleTextAttribute(color, 4); //Changes text colour to red
		cout << "////////////////////////////////////////" << endl;
		SetConsoleTextAttribute(color, 7); //Changes text colour back to white
		gameOver(name); //Function call for the gameOver function which displays game over message
		alive = false; //Sets alive to false ending while loop in main() and quitting
	}
	else if (fatState >= 4) { //Checks if fatness is above threshhold
		cout << name << " is dead from obesity. It's fat is " << fatState << "/4" << endl; // Displays message
		cout << "Fit bar:      "; // Displays message
		SetConsoleTextAttribute(color, 4); //Changes text colour to red
		cout << "////////////////////////////////////////" << endl; // Displays message
		SetConsoleTextAttribute(color, 7); //Changes text colour back to white
		gameOver(name); //Function call for the gameOver function which displays game over message
		alive = false; //Sets alive to false ending while loop in main() and quitting
	}
	else if (lazyState >= 4) { //Checks if laziness is above threshhold
		cout << name << " is dead from laziness. It's laziness is " << lazyState << "/4" << endl; // Displays message
		cout << "Activity bar: "; // Displays message
		SetConsoleTextAttribute(color, 4); // Changes text colour to red
		cout << "////////////////////////////////////////" << endl; // Dsplays message
		SetConsoleTextAttribute(color, 7); //Changes text colour back to white
		gameOver(name); //Function call for the gameOver function which displays game over message
		alive = false; //Sets alive to false ending while loop in main() and quitting
	}
	else if (dirtyState >= 4) { //Checks if dirtiness is above threshhold
		cout << name << " you pet was so dirty it died from bacteria. It's dirtiness is " << dirtyState << "/4" << endl;
		cout << "Cleanliness bar: "; // Displays message
		SetConsoleTextAttribute(color, 4); // Changes text colour to red
		cout << "////////////////////////////////////////" << endl; // Displays message
		SetConsoleTextAttribute(color, 7); // Changes text colour back to white
		gameOver(name); //Function call for the gameOver function which displays game over message
		alive = false; //Sets alive to false ending while loop in main() and quitting

	}
	else {
		switch (hungerState) {
			case 0:
				cout << endl;
				cout << name << " is well fed. It's hunger is " << hungerState << "/4" << endl; //Displays message
				cout << "   Food bar:     "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 1:
				cout << endl;
				cout << name << " is slightly peckish. It's hunger is " << hungerState << "/4" << endl; //Displays message
				cout << "   Food bar:     "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=============================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 2:
				cout << endl;
				cout << name << " is rather hungry. It's hunger is " << hungerState << "/4" << endl; //Displays message
				cout << "   Food bar:     "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "===================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 3:
				cout << endl;
				cout << name << " is starving. It's hunger is " << hungerState << "/4" << endl; //Displays message
				cout << "   Food bar:     "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=========="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			 default:
				cout << endl;
				cout << name << " is well fed. It's hunger is " << hungerState << "/4" << endl; //Displays message
				cout << "   Food bar:     "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
		}

		switch (tiredState) {
			case 0:
				cout << endl;
				cout << name << " is wide awake. It's tiredness is " << tiredState << "/4" << endl; //Displays message
				cout << "   Energy bar:   "; //Displays message 
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 1:
				cout << endl;
				cout << name << " is awake. It's tiredness is " << tiredState << "/4" << endl; //Displays message
				cout << "   Energy bar:   "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=============================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////" << endl;
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 2:
				cout << endl;
				cout << name << " is tired. It's tiredness is " << tiredState << "/4" << endl; //Displays message
				cout << "   Energy bar:   "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "===================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 3:
				cout << endl;
				cout << name << " is falling asleep. It's tiredness is " << tiredState << "/4" << endl; //Displays message
				cout << "   Energy bar:   "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=========="; //Displays message 
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			default:
				cout << endl;
				cout << name << " is wide awake. It's tiredness is " << tiredState << "/4" << endl; //Displays message
				cout << "   Energy bar:   "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
		}

		switch (fatState) {
			case 0:
				cout << endl;
				cout << name << " is very fit. It's fat is " << fatState << "/4" << endl; //Displays message
				cout << "   Fit bar:      "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 1:
				cout << endl;
				cout << name << " is somewhat fit. It's fat is " << fatState << "/4" << endl; //Displays message
				cout << "   Fit bar:      "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=============================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 2:
				cout << endl;
				cout << name << " is chubby. It's fat is " << fatState << "/4" << endl; //Displays message
				cout << "   Fit bar:      "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "===================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 3:
				cout << endl;
				cout << name << " is very fat. It's fat is " << fatState << "/4" << endl; //Displays message
				cout << "   Fit bar:      "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=========="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			default:
				cout << endl;
				cout << name << " is very fit. It's fat is " << fatState << "/4" << endl; //Displays message
				cout << "   Fit bar:      "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
		}

		switch (lazyState) {
			case 0:
				cout << endl;
				cout << name << " is very active. It's laziness is " << lazyState << "/4" << endl; //Displays message
				cout << "   Activity bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 1:
				cout << endl;
				cout << name << " is getting lazy. It's laziness is " << lazyState << "/4" << endl; //Displays message
				cout << "   Activity bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=============================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 2:
				cout << endl;
				cout << name << " is very lazy. It's laziness is " << lazyState << "/4" << endl; //Displays message
				cout << "   Activity bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "===================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 3:
				cout << endl;
				cout << name << " is a couch potato. It's laziness is " << lazyState << "/4" << endl; //Displays message
				cout << "   Activity bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=========="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			default:
				cout << endl;
				cout << name << " is very active. It's laziness is " << lazyState << "/4" << endl; //Displays message
				cout << "   Activity bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
		}

		switch (dirtyState) {
			case 0:
				cout << endl;
				cout << name << " is very clean. It's dirtiness is " << dirtyState << "/4" << endl; //Displays message
				cout << "Cleanliness bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 1:
				cout << endl;
				cout << name << " is getting dirty. It's dirtiness is " << dirtyState << "/4" << endl; //Displays message
				cout << "Cleanliness bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=============================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 2:
				cout << endl;
				cout << name << " is very dirty. It's dirtiness is " << dirtyState << "/4" << endl; //Displays message
				cout << "Cleanliness bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "===================="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			case 3:
				cout << endl;
				cout << name << " is filty. It's dirtiness is " << dirtyState << "/4" << endl; //Displays message
				cout << "Cleanliness bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "=========="; //Displays message
				SetConsoleTextAttribute(color, 4); //Changes text colour to red
				cout << "//////////////////////////////" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
			default:
				cout << endl;
				cout << name << " is very clean. It's dirtiness is " << dirtyState << "/4" << endl; //Displays message
				cout << "Cleanliness bar: "; //Displays message
				SetConsoleTextAttribute(color, 10); //Changes text colour to green
				cout << "========================================" << endl; //Displays message
				SetConsoleTextAttribute(color, 7); //Changes text colour to white
				break;
		}
	}
}

//Function which contains the main menu
void mainMenu(string name, int& money, int foodChoice, int& hamburgerInventory, int& saladInventory, int& steakInventory, int& happyLevel) { 
	void characterArt(); //function prototype
	switch (foodChoice) { //Switch statement checks what the food variable is = to and set the appropriate main main
		case 1: //HAMBURGER MENU
			cout << "======================================" << endl;
			cout << endl;
			cout << "Welcome to Martin's tamagotchi program" << endl; 
			cout << "Your pet is named: " << name << " Its happiness is " << happyLevel << "%" << endl;  
			cout << "You have " << money << " gold" << endl;
			cout << "This is your pet:" << endl;
			characterArt();
			cout << endl;
			cout << "============= MAIN MENU ==============" << endl;
			cout << "======================================" << endl;
			cout << "============= INVENTORY ==============" << endl;
			cout << endl;
			cout << "Hamburgers: " << hamburgerInventory << " || Salads: " << saladInventory << " || Steaks: " << steakInventory << endl;
			cout << "========== " << name << " can eat a: hamburger, salad, steak " << endl;
			cout << "Selected food for " << name << ":    ^^^^^^^^^" << endl;
			cout << endl;
			cout << "============== OPTIONS ===============" << endl;
			cout << endl;
			cout << "Press F to feed " << name << " a: hamburger, salad, steak " << endl;
			cout << "Press N to give " << name << " a nap (-2 tiredness, +1 hunger)" << endl;
			cout << "Press S to give " << name << " a shower (-1 tiredness, - 1 dirtiness)" << endl;
			cout << "Press B to go to the grocery store " << endl;
			cout << "Press W to make " << name << " go to work (+1 dirtiness, +1 tiredness, -1 laziness, +25 gold)" << endl;
			cout << "Press Q to quit the game." << endl;
			cout << endl;
			cout << "======================================" << endl;
			break;
		case 2: //SALAD MENU
			cout << "======================================" << endl;
			cout << endl;
			cout << "Welcome to Martin's tamagotchi program" << endl;
			cout << "Your pet is named: " << name << " Its happiness is " << happyLevel << "%" << endl;
			cout << "You have " << money << " gold" << endl;
			cout << "This is your pet:" << endl;
			characterArt();
			cout << endl;
			cout << "============= MAIN MENU ==============" << endl;
			cout << "======================================" << endl;
			cout << "============= INVENTORY ==============" << endl;
			cout << endl;
			cout << "Hamburgers: " << hamburgerInventory << " || Salads: " << saladInventory << " || Steaks: " << steakInventory << endl;
			cout << "========== " << name << " can eat a: hamburger, salad, steak " << endl;
			cout << "Selected food for " << name << ":               ^^^^^" << endl;
			cout << endl;
			cout << "============== OPTIONS ===============" << endl;
			cout << endl;
			cout << "Press F to feed " << name << " a: hamburger, salad, steak " << endl;
			cout << "Press N to give " << name << " a nap (-2 tiredness, +1 hunger)" << endl;
			cout << "Press S to give " << name << " a shower (-1 tiredness, - 1 dirtiness)" << endl;
			cout << "Press B to go to the grocery store " << endl;
			cout << "Press W to make " << name << " go to work (+1 dirtiness, +1 tiredness, -1 laziness, +25 gold)" << endl;
			cout << "Press Q to quit the game." << endl;
			cout << endl;
			cout << "======================================" << endl;
			break;
		case 3: //Steak menu
			cout << "======================================" << endl;
			cout << endl;
			cout << "Welcome to Martin's tamagotchi program" << endl;
			cout << "Your pet is named: " << name << " Its happiness is " << happyLevel << "%" << endl;
			cout << "You have " << money << " gold" << endl;
			cout << "This is your pet:" << endl;
			characterArt();
			cout << endl;
			cout << "============= MAIN MENU ==============" << endl;
			cout << "======================================" << endl;
			cout << "============= INVENTORY ==============" << endl;
			cout << endl;
			cout << "Hamburgers: " << hamburgerInventory << " || Salads: " << saladInventory << " || Steaks: " << steakInventory << endl;
			cout << "========== " << name << " can eat a: hamburger, salad, steak " << endl;
			cout << "Selected food for " << name << ":                      ^^^^^" << endl;
			cout << endl;
			cout << "============== OPTIONS ===============" << endl;
			cout << endl;
			cout << "Press F to feed " << name << " a: hamburger, salad, steak " << endl;
			cout << "Press N to give " << name << " a nap (-2 tiredness, +1 hunger)" << endl;
			cout << "Press S to give " << name << " a shower (-1 tiredness, - 1 dirtiness)" << endl;
			cout << "Press B to go to the grocery store " << endl;
			cout << "Press W to make " << name << " go to work (+1 dirtiness, +1 tiredness, -1 laziness, +25 gold)" << endl;
			cout << "Press Q to quit the game." << endl;
			cout << endl;
			cout << "======================================" << endl;
			break;
		default: //No input menu
			cout << "======================================" << endl;
			cout << endl;
			cout << "Welcome to Martin's tamagotchi program" << endl;
			cout << "Your pet is named: " << name << " Its happiness is "<< happyLevel << "%" << endl;
			cout << "You have " << money << " gold" << endl;
			cout << "This is your pet:" << endl;
			characterArt();
			cout << endl;
			cout << "============= MAIN MENU ==============" << endl;
			cout << "======================================" << endl;
			cout << "============= INVENTORY ==============" << endl;
			cout << endl;
			cout << "Hamburgers: " << hamburgerInventory << " || Salads: " << saladInventory << " || Steaks: " << steakInventory << endl;
			cout << "Selected food for " << name << ": Nothing is selected. Use 1, 2 or 3 to select" << endl;
			cout << endl;
			cout << "============== OPTIONS ===============" << endl;
			cout << endl;
			cout << "Press F to feed " << name << " a: hamburger, salad, steak " << endl;
			cout << "Press N to give " << name << " a nap (-2 tiredness, +1 hunger)" << endl;
			cout << "Press S to give " << name << " a shower (-1 tiredness, - 1 dirtiness)" << endl;
			cout << "Press B to go to the grocery store " << endl;
			cout << "Press W to make " << name << " go to work (+1 dirtiness, +1 tiredness, -1 laziness, +25 gold)" << endl;
			cout << "Press Q to quit the game." << endl;
			cout << endl;
			cout << "======================================" << endl;
			break;
	}

	inMain = true; //Sets variable to true indicating we are in the main menu
	inShop = false; //Sets variable to false inficating we are not in the shop menu
} 

//Function which contains the contents of the shop menu
void shopMenu(int& money, int& hamburgerInventory, int& saladInventory, int& steakInventory) {
	cout << "======================================" << endl;
	cout << "Welcome to the SHOP" << endl;
	cout << "You have: " << money << " gold" << endl;
	cout << "======================================" << endl;
	cout << "================= SHOP ===============" << endl;
	cout << "Press 1 to buy a hamburger (+2 food, +2 fat, - 10 gold). Hamburger count: " << hamburgerInventory << endl;
	cout << "Press 2 to buy a salad (+1 food, -1 fat, -15 gold). Salad count: " << saladInventory << endl;
	cout << "Press 3 to buy a steak (+3 food, +1 fat, -20 gold). Steak count: " << steakInventory << endl;
	cout << "Press B to go back to main menu" << endl;
	cout << "Press Q to quit the game." << endl;
	cout << "======================================" << endl;
	inMain = false; //Sets variable to false to indicate we are not in the main menu
	inShop = true; //Sets variable to true to indicate we are in the shop menu
}

//Function which contains the game over menu
void gameOver(string name) {
	void clear(); //Clears display
	cout << endl;
	cout << "======================================" << endl;
	cout << name << " has died" << endl;



	cout << "                       ." << endl;
	cout << "                      -|-" << endl;
	cout << "                       |" << endl;
	cout << "                   .-'~~~`-." << endl;
	cout << "                 .'         `." << endl;
	cout << "                 |  R  I  P  |" << endl;
	cout << "                 | " << name << endl;
	cout << "                 |           |" << endl;
	cout << "               \\|           |//" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

//Function which allows clearing of display
void clear() {
	system("CLS");
}

//Function which makes the character go work and increases and decreases the appropriate stats
void goWork(string name, int& money, int& hungerLevel, int& tiredLevel, int& lazyLevel, int& dirtyLevel, int& happyLevel) {
	cout << "======================================" << endl;
	cout << name << " went to work and made 25 gold" << endl;
	cout << "======================================" << endl;
	money += 25; //Adds to the gold variable

	if (lazyLevel <= 0) { //Checks if laziness is under so it does not go to negative numbers
		lazyLevel = 0; //Resets laziness
		tiredLevel++; //Increases tiredness
		hungerLevel++; //Increases hunger
		dirtyLevel++; //Increases dirtiness
		happyLevel -= 15; //Decreases happiness
	}
	else {
		happyLevel -= 10; //Decreases happiness
		hungerLevel++; //Increases hunger
		tiredLevel++; //Increases tiredness
		dirtyLevel++; //Increases dirtiness
		lazyLevel--; //Decreases laziness
	}
}

//Function which makes the character go take a shower and increases and decreases the appropriate stats
void takeShower(int& tiredLevel, int& dirtyLevel, int& happyLevel) {

	if (tiredLevel <= 0) {  //Checks if tiredness is under so it does not go to negative numbers
		tiredLevel = 0; //Reset tiredness
		happyLevel += 5; //Increase happiness
		dirtyLevel--; //Decrease dirtiness
	}
	else if (dirtyLevel <= 0) { //Checks if dirtiness is under so it does not go to negative numbers
		dirtyLevel = 0; //Reset dirtiness
		happyLevel += 5; //Increase happiness
		tiredLevel--; //Decrease tiredness
	}
	else {
		tiredLevel--; //Decrease tiredness
		dirtyLevel--; //Decrease dirtiness
		happyLevel += 10; //Increase happiness
	}



}

//Function containing the character that gets displayed on screen.
void characterArt() {
	cout << endl;
	cout << "	.^. .^. " << endl;
	cout << "	| . . | " << endl;
	cout << "       (  ---  )" << endl;
	cout << "       .'     '." << endl;
	cout << "       ||     ||" << endl;
	cout << "	| | | | " << endl;
	cout << "         V   V  " << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}