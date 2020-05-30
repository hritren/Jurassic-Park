#include"ZooManager.h"

void ZooManager::menu()
{
	system("cls");
	cout << "1. Add dinosaur" << endl;
	cout << "2. Add cell" << endl;
	cout << "3. Remove dinosaur" << endl;
	cout << "4. Store food" << endl;
	cout << "5. Exit" << endl;
	int option;
	cin >> option;
	if (option == 1)
	{
		addDino();
		menu();
	}
	if (option == 2)
	{
		addCell();
		menu();
	}
	if (option == 3)
	{
		removeDino();
		menu();
	}
	if (option == 4)
	{
		store();
		menu();
	}
	else
		save();
}
void ZooManager::addDino()
{
	system("cls");
	cout << "Enter name " << endl;
	cin.ignore();
	char name[30];
	cin.getline(name, 30);
	system("cls");
	cout << "Enter kind " << endl;
	char kind[30];
	cin.getline(kind, 30);
	Sex sex;
	Era era;
	Food food;
	bool classification[4];
	system("cls");
	cout << "Sex:" << endl;
	cout << "1. Male" << endl;
	cout << "2. Female" << endl;
	int option;
	cin >> option;
	if (option == 1)
		sex = male;
	else
		sex = female;
	system("cls");
	cout << "Era:" << endl;
	cout << "1. Triassic" << endl;
	cout << "2. Cretaceous" << endl;
	cout << "3. Jurassic" << endl;
	cin >> option;
	if (option == 1)
		era = Triassic;
	if (option == 2)
		era = Cretaceous;
	else
		era = Jurassic;
	system("cls");
	cout << "Food:" << endl;
	cout << "1. Grass" << endl;
	cout << "2. Meat" << endl;
	cout << "3. Fish" << endl;
	cin >> option;
	if (option == 1)
		food = grass;
	if (option == 2)
		food = meat;
	else
		food = fish;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " herbivorous?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[0] = true;
	else
		classification[0] = false;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " carnivorous?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[1] = true;
	else
		classification[1] = false;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " flying?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[2] = true;
	else
		classification[2] = false;
	system("cls");
	cout << "Classification:" << endl;
	cout << "Is " << name << " aquous?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> option;
	if (option == 1)
		classification[3] = true;
	else
		classification[3] = false;
	Dino d(name, sex, era, kind, food, classification);
	zoo.addDino(d);
}
void ZooManager::addCell()
{
	Cell cell;
	zoo.addCell(cell);
}
void ZooManager::removeDino()
{
	char name[30];
	cin.getline(name, 30);
	zoo.removeDino(name);
}
void ZooManager::store()
{
	system("cls");
	int quantity;
	cout << "How much grass do you want to add?" << endl;
	cin >> quantity;
	zoo.addFood("grass", quantity);
	cout << "How much meat do you want to add?" << endl;
	cin >> quantity;
	zoo.addFood("meat", quantity);
	cout << "How much fish do you want to add?" << endl;
	cin >> quantity;
	zoo.addFood("fish", quantity);
}
void ZooManager::save()
{
	saveToFile("Zoo.txt", zoo);
}
ZooManager::ZooManager()
{
	zoo.readFromFile("Zoo.txt");
}