#include <iostream>
#include <string>
#include "inventory.h"

std::string input;
bool loop = true;
int HP{ 10 };

Item apple{ "Apple", 3, 5 };
Item scrap{ "Scrap", 2, 10 };

int main() {
	Inventory playerInv{ 100, 0 };
	Inventory ShopInv{ 1000000, 10000000 };
	playerInv.GetThing(apple);
	playerInv.GetThing(apple);
	playerInv.GetThing(scrap);

	std::cout << "Hello! Welcome to my game! Input Y to play, others to quit.\n" << "Input: ";
	std::cin >> input;

	if (input == "Y" || input == "y") 
	{
		std::cout << "...\n";
		std::cout << "......\n";
		std::cout << ".........\n";
		std::cout << "You just woke up from the apocalypse!\n";
		std::cout << "Now you have 10HP, 0 food, 0 resource and 0 money.\n";
		std::cout << "To gain food or resource you need to take on an adventure, which cost you 2 HP and 2 foods.\n";
		std::cout << "If you have not enough food, your adventure will cost you 5 HP and you gain less resources.\n";
		std::cout << "You have several options: GoAdventure, GoShop and Inventory.\n";
		std::cout << "Input your option to go on.\n";
		std::cout << "To quit, type 'quit()'.\n";
		std::cout << "\n";
		
		while (loop) 
		{
			if (HP <= 0)
			{
				std::cout << "You Died.\n\n";
				loop = false;
			}

			std::cout << "Input: ";
			std::cin >> input;

			if (input == "GoAdventure") 
			{
				if (playerInv.GetThingQty(apple) > 1) 
				{
					HP = HP - 2;
					std::cout << "Your current HP = " << HP << "\n\n";
					playerInv.GetThing(scrap);
					playerInv.GetThing(scrap);
					playerInv.LoseThing(apple);
					playerInv.LoseThing(apple);
					std::cout << "You found 2 scraps!\n\n";
					continue;
				}

				HP = HP - 5;
				std::cout << "Your current HP = " << HP << "\n\n";
				playerInv.SetThingQty(apple, 0);
				playerInv.GetThing(scrap);
				std::cout << "You lack of food and starved!...\n\n";
				std::cout << "You lost 5 HP, Your current HP = " << HP << "\n\n";
				std::cout << "But you found 1 scraps!\n\n";
			}

			if (input == "GoShop") 
			{
				std::cout << "Items for sale: Apple, value = 10\n";
				std::cout << "Items for trade: scrap, value = 10\n";
				std::cout << "Enter BuyApple to buy one apple, SellScrap to sell one scrap. Back to go back adventure.\n";
					
				while (input != "back") 
				{
					std::cout << "Shop Input: ";
					std::cin >> input;
					if (input == "BuyApple")
					{
						playerInv.BuyThingFrom(apple, ShopInv);
						continue;
					}
					if (input == "SellScrap")
					{
						playerInv.SellThingTo(scrap, ShopInv);
						continue;
					}
				}
					
				std::cout << "You got home.\n";
				std::cout << "You have several options: GoAdventure, GoShop and Inventory.\n";
				std::cout << "Input your option to go on.\n";
				std::cout << "To quit, type 'quit()'.\n";
				continue;
			}

			if (input == "Inventory") 
			{
				playerInv.ShowInv();
				continue;
			}

			if (input == "quit()") 
			{
				loop = false;
				continue;
			}

			std::cout << "Please input something that makes sense.\n";
		}
	}
	std::cin.get();
}