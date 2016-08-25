/*********************************************************************
** Program Filename : Boffy CPP 
** Author : Tyler Forrester
** Date : 7 / 18 / 2016
** Description : Boffy Class for Fantasy Game
** Input : Attacks
** Output : Losses
** Citations :
********************************************************************/

#include "Boffy.hpp"


/*********************************************************************
** Function: Boffy Constructor
** Description: Intializes Boffy Strength and Armor in Creature Class
** Parameters: void and Creature(Armor, Strength)
** Pre-Conditions: pick()
** Post-Conditions: battle()
** Citation:
*********************************************************************/


Boffy::Boffy() : Creature(3, 8) // passes armor and strength to creature class constructor
{ 
}


/*********************************************************************
** Function: Boffy attack()
** Description: Allows players to use items in attack that might give some advantage.
** Parameters: void
** Pre-Conditions: battle()
** Post-Conditions: def()
** Citation:
*********************************************************************/


int Boffy::attack()
{

	char entry; // some variables for user input
	char yes; 
	InputValid valid = InputValid(); // some validation
	cout << "Would you like to check your bags for a items?" << endl; // lets player check for items
	cout << "Please enter y for yes. Any other character to skip\n"; // player must confirmat
	yes = valid.validateChar();

	if (yes = 'y')
	{

		if (checkItems("Sword of Gabriel")) { // if item found asks user to use it

			cout << "You have the Sword of Gabriel would you like to use it?\n";
			cout << "Please enter y for yes.\n";
			entry = valid.validateChar();

			if (entry == 'y') {
				std::cout << "You swing Gabriel's Sword at the the Dreamwalker\n";
				valid.continueOn();
				std::cout << "The SWORD BREAKS.\n";  // outcome
				std::cout << "You SCREAM!!! Your attack returns 18.\n";
				return 18;
			}
			
			cout << "You chose not to use the Sword of Gabriel." << endl; // tells player they didn't use it. 
			entry = 'a'; 
		}

		else {

		cout << "You don't have the Sword of Gabriel. You should find it\n"; // otherwise let's player know item exists
		
		
		}
		valid.continueOn();

		if (checkItems("Sleeping Powder")) { // same pattern, probably a function in phase 2

			cout << "You have some Sleeping Powder would you like to use it?\n";
			cout << "Please enter y for yes.\n";
			entry = valid.validateChar();

			if (entry == 'y') {
				std::cout << "You toss the sleeping powder in the direction of Eyghor!\n";
				valid.continueOn();
				std::cout << "A gust of wind blows the sleeping powder back into your face.\n";
				std::cout << "You sneeze!!! Your attack returns 0.\n";
				return 0;
			}
			cout << "You chose not to use the Sleeping Powder." << endl;
			entry = 'a';


		}
		else {


			cout << "You don't have any Sleeping Powder. Maybe you should find some?\n";


		}
		valid.continueOn();
		
		if (checkItems("Light Orb")) { // game winning item, probably a function in phase 2

			cout << "You have the Light Orb would you like to use it?\n";
			cout << "Please enter y for yes. All other characters will not activate the Light Orb.\n";
			entry = valid.validateChar();

			if (entry == 'y') {
				std::cout << "The Light Orb's energy explodes out of Boffy's Packet Pack.\n";
				std::cout << "The world turns WHITE.\n";
				valid.continueOn();
				std::cout << "Your attack returns 200,000. Eyghor is dead!!!\n";
				return 200000;
			}
			cout << "You chose not to use the light orb." << endl;

		}
		else {

			cout << "You need the Light Orb. Without Light there is only darkness.\n";



		}

		valid.continueOn();
		 


	}
		int at = play(3, 6); // Boffy rolls extra die for amulet of power
		std::cout << "Boffy has amulet of power is activated !\n";  // else some meaningless attack
		std::cout << "Boffy has struck with a "<< at << " in attack.\n";
		return (at);
	
	
	
	 
	
}

/*********************************************************************
** Function: Boffy defense()
** Description: takes attack and returns Boffy health
** Parameters: int attack
** Pre-Conditions: battle() attack()
** Post-Conditions: damage() then battle() or main()
** Citation:
*********************************************************************/

 void Boffy::defense(int attack)
{
	//std::cout << "Boffy's Strength before Attack is " << getStrength() << ".\n"; // used for testing
	int def = play(1,6); // calls play function to roll dies
	
	std::cout << "Boffy has rolled a " << def << " in Defence.\n";
	
	int health = getStrength() - damage(def, attack); // gets health after attack
	
	std::cout << "Boffy's total damage is " << damage(def, attack) << ".\n\n"; // output to play along
	
	setStrength(health); // sets creatures strength in creature class

	// std::cout << "Boffy's strength is " << getStrength() << ".\n\n"; // output for testing
	
	
}

