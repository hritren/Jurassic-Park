#include"Dino.h"

enum Climate{earth, air, water};
const int values[3] = { 1, 3, 10 };

///This is the class Cell which describes a cell. It has an array of dinos, size, era, climate, freeSpace
class Cell
{
private:
	///Array of 10 dinosaurs
	Dino dinos[10];
	///For the size I use int which can be 1/3/10
	int size;
	///For the era I use enum type with values {Triassic, Cretaceous, Jurassic, other}
	Era era;
	///For the climate I use enum type with values {earth, air, water}
	Climate climate;
	///For the size I use int which shows for how many more dinos there is space in the cell
	int freeSpace;
public:
	///Default constructor. Gives random values
	Cell();
	///Constructor with parameters
	Cell(Climate climate, Era era, int size);
	///Function that puts a dinosaur in the cell. Returns true if it was successful and false otherwise
	bool addDino(Dino dino);
	///Function that removes a dinosaur with a particular name from the cell. Returns true if it was successful and false otherwise
	bool removeDino(const char* name);
	///Function that returns the climate of a cell
	Climate getClimate() const;
	///Function that returns the era of a cell
	Era getEra() const;
	///Function that returns the size of a cell
	int getSize() const;
	///Function that returns the freeSpace of a cell
	int getFreeSpace() const;
	///Function that returns the Dino in the index position in the cell
	Dino getDinoAt(int index) const;
};