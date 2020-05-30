#include"Dino.h"

#pragma warning(disable : 26812	)

void Dino::Free()
{
	delete[] name;
	delete[] kind;
}
void Dino::CopyFrom(const Dino& other)
{
	name = new char[strlen(other.name) + 1];
	kind = new char[strlen(other.kind) + 1];
	strcpy(name, other.name);
	strcpy(kind, other.kind);
	sex = other.sex;
	era = other.era;
	for (int i = 0; i < 4; i++)
	{
		classification[i] = other.classification[i];
	}
	food = other.food;
}
Dino::Dino()
{
	name = new char[8];
	strcpy(name, "No name");
	kind = new char[8];
	strcpy(name, "No kind");
	sex = male;
	era = other;
	for (int i = 0; i < 4; i++)
	{
		classification[i] = false;
	}
	food = grass;
}
Dino::~Dino()
{
	Free();
}
Dino::Dino(const Dino& other)
{
	CopyFrom(other);
}
Dino& Dino::operator=(const Dino& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Dino::Dino(const char* name, Sex sex, Era era, const char* kind, Food food, bool clas[4])
{
	this->name = new char[strlen(name) + 1];
	this->kind = new char[strlen(kind) + 1];
	strcpy(this->name, name);
	strcpy(this->kind, kind);
	this->sex = sex;
	this->era = era;
	this->food = food;
	for (int i = 0; i < 4; i++)
	{
		classification[i] = clas[i];
	}
}
const char* Dino::getName() const
{
	return name;
}
Era Dino::getEra() const
{
	return era;
}
bool Dino::isAqueous() const
{
	return classification[3];
}
bool Dino::isFlying() const
{
	return classification[2];
}
Food Dino::getFood() const
{
	return food;
}
const char* Dino::getKind() const
{
	return kind;
}
Sex Dino::getSex() const
{
	return sex;
}
bool Dino::isHerbivorous() const
{
	return classification[0];
}
bool Dino::isCarnivorous() const
{
	return classification[1];
}