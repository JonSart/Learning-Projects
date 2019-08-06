//Jonathan Simpson. 8/5/19. Creating an inventory system to learn linked lists. 
#include <iostream>
#include <list>
#include <iterator>
#include <string>

using std::cout;
using std::cin;
using std::list;
using std::string;

void Menu();

class Inventory
{
public:
	void AddItem(string);
	void View();
	void Delete();

private:

	list <string> inv;
};


void Inventory::AddItem(string x)
{
	inv.push_back(x);
	View();
}

void Inventory::View()
{
	int x = 1;
	cout << "******INVENTORY******\n";

	for (list<string>::iterator i = inv.begin(); i != inv.end(); i++)
	{
		cout << x << ": " << *i << ".\n";
		x++;
	}
	cout << "*********************\n";
}

void Inventory::Delete()
{
	string ans = "";

	while (ans != "exit")
	{
		cout << "Which item would you like to delete?\n"
			<< "Type 'exit' to exit the delete menu.\n";
		View();

		cin >> ans;

		if (ans != "exit")
			inv.remove(ans);
	}
}

int main()
{
	cout << "Welcome to Inventory Management!\n";
	Menu();
	cout << "Goodbye!";
}

void Menu()
{
	Inventory inventory;
	string answer = "";
	bool menuLoop = true;

	while (menuLoop)
	{
		cout << "Enter the name of an item you would like to add to your inventory.\n"
			<< "Type 'exit' to exit, 'delete' to delete an item, and 'view' to view the list.\n";

		cin >> answer;

		if (answer == "view")
			inventory.View();
		else if (answer == "exit")
			return;
		else if (answer == "delete")
			inventory.Delete();
		else
			inventory.AddItem(answer);
	}
}