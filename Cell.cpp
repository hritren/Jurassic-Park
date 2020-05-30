#include"Cell.h"

#pragma warning(disable : 26812	)


Cell::Cell()
{
	size = values[rand() % 3];
	era = Era(rand() % 3);
	climate = Climate(rand() % 3);
	freeSpace = size;
}
Cell::Cell(Climate climate, Era era, int size)
{
	this->climate = climate;
	this->size = size;
	this->era = era;
	freeSpace = size;
}
bool Cell::addDino(Dino dino)
{
	if (!freeSpace)
		return false;
	dinos[size - freeSpace] = dino;
	freeSpace--;
	return true;
}
bool Cell::removeDino(const char* name)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(dinos[i].getName(), name))
		{
			index = i;
			break;
		}
	}
	if (index == -1)
		return false;
	for (int i = index; i < size; i++)
	{
		if (index == size - 1)
			dinos[i] = Dino();
		else
			dinos[i] = dinos[i + 1];
	}
	freeSpace++;
	return true;
}
Climate Cell::getClimate() const
{
	return climate;
}
Era Cell::getEra() const
{
	return era;
}
int Cell::getSize() const
{
	return size;
}
int Cell::getFreeSpace() const
{
	return freeSpace;
}
Dino Cell::getDinoAt(int index) const
{
	return dinos[index];
}