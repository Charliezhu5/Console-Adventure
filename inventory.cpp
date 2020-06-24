#include "inventory.h"


Inventory::Inventory(int capacity, int money) : _capacity(capacity), _money(money) 
{

}

void Inventory::GetMoney(int amount) 
{
	_money += amount;
}

void Inventory::BuyThingFrom(Item& thing, Inventory& inventory) 
{

	if ((_currentWeight + thing.weight) > _capacity) 
	{
		std::cout << "Over Capacity! Cannot buy!\n";
		return;
	}

	if (_money < thing.value) {
		std::cout << "Insufficient funds!\n";
		return;
	}

	// lose money and gain item
	_money -= thing.value;
	_items[thing]++;
	_currentWeight = GetCurrentWeight();
	std::cout << "You paid " << thing.value << " money to buy one " << thing.name << "!\n";
	std::cout << "You currently have " << _money << " money in your pocket!\n";
}

void Inventory::GetThing(Item& thing) 
{
	if ((_currentWeight + thing.weight) > _capacity) {
		std::cout << "Over Capacity! You did not get anything!\n";
		return;
	}
	// gain item
	_items[thing]++;
	_currentWeight = GetCurrentWeight();
}

void Inventory::SellThingTo(Item& thing, Inventory& inventory) 
{
	if (inventory.GetCurrentMoney() < thing.value) 
	{
		std::cout << "Shop has insufficient funds! Come another day!\n";
		return;
	}
	if (_items.find(thing) != _items.end() && _items[thing] > 0) 
	{ // if this thing is in the map and has more than 0 qty.
		// lose item gain money.
		_money += thing.value;
		_items[thing]--;
		_currentWeight = GetCurrentWeight();
		std::cout << "You got " << thing.value << " money by selling one " << thing.name << "!\n";
		std::cout << "You currently have " << _money << " money in your pocket!\n";
		return;
	}
	std::cout << "You don't have one!\n";
}

void Inventory::LoseThing(Item& thing) 
{
	// Lose item
	if (_items.find(thing) != _items.end() && _items[thing] > 0)
	{
		_items[thing]--;
		_currentWeight = GetCurrentWeight();
		std::cout << "You lost one " << thing.name << " !\n";
	}
}

void Inventory::ShowInv() const 
{
	// show inventory
	std::cout << "You have " << _money << " money! And...\n";
	std::cout << "Your capacity " << _currentWeight << " /100 And...\n";

	std::cout << "\tItem\tQuantity\n";
	for (auto itr = _items.begin(); itr != _items.end(); ++itr) 
	{
		std::cout << '\t' << itr->first.name
			<< '\t' << itr->second << '\n';
	}
}

int Inventory::GetCurrentWeight() const
{
	int current{ 0 };
	for (auto itr = _items.begin(); itr != _items.end(); ++itr)
	{
		current += itr->first.weight * itr->second;
	}
	return current;
}

int Inventory::GetCurrentMoney() const
{
	return _money;
}

int Inventory::GetThingQty(Item& thing) const
{
	return _items.at(thing);
}

void Inventory::SetThingQty(Item& thing, int qty)
{
	_items[thing] = qty;
}