#include<iostream>
#include<cstring>
#include<fstream>
#include <time.h>
#include <stdlib.h>

#pragma warning(disable : 4996)


using namespace std;

enum Sex{male, female};
enum Era {Triassic, Cretaceous, Jurassic, other};
//enum Classification {herbivorous, carnivorous, flying, aqueous};
enum Food {grass, meat, fish};
///This is the class Dino which describes a dinosaur. It has a name, sex, era, kind, food and classification
class Dino
{
private:
	///For the name I use char*
	char* name;
	///For the sex I use enum type with values {male, female}
	Sex sex;
	///For the era I use enum type with values {Triassic, Cretaceous, Jurassic, other}
	Era era;
	///For the kind I use char*
	char* kind;
	///For the food I use enum type with values {grass, meat, fish}
	Food food;
	///For the classification I use a boolean array where 0-herbivorous, 1-carnivorous, 2-flying, 3-aqueous
	bool classification[4];
	///Private function that frees allocated memory
	void Free();
	///Private function that copies a Dino
	void CopyFrom(const Dino& other);
public:
	///Default constructor. Allocates memory, gives default values
	Dino();
	///Destructor. Frees allocated memory
	~Dino();
	///Copy constructor
	Dino(const Dino& other);
	///Operator=
	Dino& operator=(const Dino& other);
	///Constructor with parameters
	Dino(const char* name, Sex sex, Era era, const char* kind, Food food, bool clas[4]);
	///Function that returns the name of a Dino
	const char* getName() const;
	///Function that returns the kind of a Dino
	const char* getKind() const;
	///Function that returns the sex of a Dino
	Sex getSex() const;
	///Function that returns the era of a Dino
	Era getEra() const;
	///Function that returns the food of a Dino
	Food getFood() const;
	///Function that returns if the Dino is flying
	bool isFlying() const;
	///Function that returns if the Dino is aqueous
	bool isAqueous() const;
	///Function that returns if the Dino is herbivourous
	bool isHerbivorous() const;
	///Function that returns if the Dino is carnivorous
	bool isCarnivorous() const;
};