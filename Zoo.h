#include"Cell.h"

///This is the class Zoo which describes a zoo. It has an array of cells, foodStorage, capacity and current
class Zoo
{
private:
	///For the foodStorage I use a boolean array where 0-grass, 1-meat, 2-fish
	int foodStorage[3];// 0-grass, 1-meat, 2-fish
	///For the cells I use a pointer to Cell
	Cell* cells;
	///For the capacity I use int
	int capacity;
	///For the current I use int
	int current;
	///Private function that frees allocated memory
	void Free();
	///Private function that copies a Dino
	void Copyfrom(const Zoo& other);
	///Private function that resize the array of cells
	void resize();
	///Friend function that saves a zoo in a file
	friend void saveToFile(const char* filename,const Zoo& zoo);
public:
	///Default constructor. Allocates memory, gives default values
	Zoo();
	///Destructor. Frees allocated memory
	~Zoo();
	///Copy constructor
	Zoo(const Zoo& other);
	///Operator=
	Zoo& operator=(const Zoo& other);
	///Function that adds a dino in the zoo
	void addDino(Dino dino);
	///Function that adds a random cell in the zoo
	void addCell(const Cell& cell);
	///Function that removes a dino with a particular name from the zoo
	bool removeDino(const char* name);
	///Function that adds food in the food storage
	void addFood(const char* food, int quantity);
	///Function that returns current
	int getCurrent() const;
	///Function that returns the amount of grass
	int getGrass() const;
	///Function that returns the amount of meat
	int getMeat() const;
	///Function that returns the amount of fish
	int getFish() const;
	///Function that returns the size of the index cell
	int getCellSizeAt(int index) const;
	///Function that returns the free space in the index cell
	int getFreeSpaceAt(int index) const;
	///Function that returns the era of the index cell
	Era getEraAt(int index) const;
	///Function that returns the climate of the index cell
	Climate getClimateAt(int index) const;
	///Function that returns the index2 Dino in the index1 cell
	Dino getDinoAt(int index1, int index2) const;
	///Function that reads a zoo from a file
	void readFromFile(const char* filename);
};
void saveToFile(const char* filename, const Zoo& zoo);