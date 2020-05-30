#include"Zoo.h"

///This the class ZooManager which manages a zoo
class ZooManager
{
public:
	///Default constructor. Reads a zoo from a file
	ZooManager();
	///Function that desplays options
	void menu();
private:
	///A zoo
	Zoo zoo;
	///Private function that adds a dinosaur in the zoo
	void addDino();
	///Private function that adds a cell in the zoo
	void addCell();
	///Private function that removes a dinosaur in the zoo
	void removeDino();
	///Private function that adds a food in the storage
	void store();
	///Private function that saves the zoo in the same file it was read from
	void save();
};
