#pragma once

#include <iostream>
#include <string>
#include <map>
#include <iterator>

struct Item 
{
public:
	std::string name;
	int weight;
	int value;
	Item(std::string name, int weight, int value) : name(name), weight(weight), value(value) {}

	bool operator< (const Item& userObj) const
	{
		if (userObj.name < this->name)
			return true;
	}
};

class Inventory
{
private:
	int _capacity;
	int _currentWeight;
	int _money;
	std::map<Item, int> _items;

public:
	Inventory(int capacity, int money);
	void GetMoney(int amount);
	void BuyThingFrom(Item& thing, Inventory& inventory);
	void SellThingTo(Item& thing, Inventory& inventory);
	void GetThing(Item& thing);
	void LoseThing(Item& thing);
	void ShowInv() const;
	int GetCurrentWeight() const;
	int GetCurrentMoney() const;
	int GetThingQty(Item& thing) const;
	void SetThingQty(Item& thing, int qty);
};