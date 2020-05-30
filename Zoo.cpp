#include"Zoo.h"

void Zoo::Free()
{
	delete[] cells;
}
void Zoo::Copyfrom(const Zoo& other)
{
	capacity = other.capacity;
	current = other.current;
	for (int i = 0; i < current; i++)
	{
		cells[i] = other.cells[i];
	}
	for (int i = 0; i < 3; i++)
	{
		foodStorage[i] = other.foodStorage[i];
	}
}
void Zoo::resize()
{
	capacity *= 2;
	Cell* tmp = new Cell[capacity];
	for (int i = 0; i < current; i++)
	{
		tmp[i] = cells[i];
	}
	Free();
	cells = tmp;
}
Zoo::Zoo()
{
	int random = rand() % 10 + 1;
	capacity = random * 2;
	current = random;
	cells = new Cell[capacity];
	for (int i = 0; i < 3; i++)
		foodStorage[i] = 0;
}
Zoo::~Zoo()
{
	Free();
}
Zoo::Zoo(const Zoo& other)
{
	Copyfrom(other);
}
Zoo& Zoo::operator=(const Zoo& other)
{
	if (this != &other)
	{
		Free();
		Copyfrom(other);
	}
	return *this;
}
void Zoo::addCell(const Cell& cell)
{
	if (current == capacity) {
		resize();
	}
	cells[current] = cell;
	current++;
}
void Zoo::addDino(Dino dino)
{
	int index = 0;
	Climate climate;
	if (dino.isAqueous())
		climate = water;
	else
		if (dino.isFlying())
			climate = air;
		else
			climate = earth;
	bool flag = false;
	while (!flag && index < current)
	{
		if(climate == cells[index].getClimate() && dino.getEra() == cells[index].getEra())
			flag = cells[index].addDino(dino);
		index++;
	}
	if (!flag)
	{
		int size;
		cout << "Size of the cell:" << endl;
		cin >> size;
		if (size != 1 && size != 3 && size != 10)
			size = 1;
		Cell cell(climate, dino.getEra(), size);
		cell.addDino(dino);
		addCell(cell);
	}
}
bool Zoo::removeDino(const char* name)
{
	int index = 0;
	bool flag = false;
	while (!flag && index < current)
	{
		flag = cells[index++].removeDino(name);
	}
	return flag;
}
void Zoo::addFood(const char* food, int quantity)
{
	if (!strcmp(food, "grass"))
		foodStorage[0] += quantity;
	else
		if(!strcmp(food, "meat"))
			foodStorage[1] += quantity;
		else
			if(!strcmp(food, "fish"))
				foodStorage[2] += quantity;
}
void saveToFile(const char* filename,const Zoo& zoo)
{
	ofstream oFile(filename, ios::binary);
	int cellsNum = zoo.getCurrent();
	int grass = zoo.getGrass();
	int meat = zoo.getMeat();
	int fish = zoo.getFish();
	oFile.write((char*)&cellsNum, sizeof(int));
	oFile.write((char*)&grass, sizeof(int));
	oFile.write((char*)&meat, sizeof(int));
	oFile.write((char*)&fish, sizeof(int));
	for (int i = 0; i < cellsNum; i++)
	{
		int size = zoo.getCellSizeAt(i), freeSpace = zoo.getFreeSpaceAt(i);
		Era era = zoo.getEraAt(i);
		Climate climate = zoo.getClimateAt(i);
		oFile.write((char*)&size, sizeof(int));
		oFile.write((char*)&freeSpace, sizeof(int));
		oFile.write((char*)&era, sizeof(Era));
		oFile.write((char*)&climate, sizeof(Climate));
		for (int j = 0; j < size - freeSpace; j++)
		{
			Dino dino = zoo.getDinoAt(i, j);
			int nameLen = strlen(dino.getName()) + 1;
			char* dinoName = new char[nameLen];
			strcpy(dinoName, dino.getName());
			oFile.write((char*)&nameLen, sizeof(int));
			oFile.write((char*)dinoName, sizeof(char) * nameLen);

			int kindLen = strlen(dino.getKind()) + 1;
			char* dinoKind = new char[kindLen];
			strcpy(dinoKind, dino.getKind());
			oFile.write((char*)&kindLen, sizeof(int));
			oFile.write((char*)dinoKind, sizeof(char) * kindLen);

			Era dinoEra = dino.getEra();
			Food food = dino.getFood();
			Sex sex = dino.getSex();
			oFile.write((char*)&dinoEra, sizeof(Era));
			oFile.write((char*)&food, sizeof(Food));
			oFile.write((char*)&sex, sizeof(Sex));

			bool is0 = dino.isHerbivorous();
			bool is1 = dino.isCarnivorous();
			bool is2 = dino.isFlying();
			bool is3 = dino.isAqueous();
			oFile.write((char*)&is0, sizeof(bool));
			oFile.write((char*)&is1, sizeof(bool));
			oFile.write((char*)&is2, sizeof(bool));
			oFile.write((char*)&is3, sizeof(bool));

			delete[] dinoName;
			delete[] dinoKind;
		}
	}
}
int Zoo::getCurrent() const
{
	return current;
}
int Zoo::getGrass() const
{
	return foodStorage[0];
}
int Zoo::getMeat() const
{
	return foodStorage[1];
}
int Zoo::getFish() const
{
	return foodStorage[2];
}
int Zoo::getCellSizeAt(int index) const
{
	return cells[index].getSize();
}
int Zoo::getFreeSpaceAt(int index) const
{
	return cells[index].getFreeSpace();
}
Era Zoo::getEraAt(int index) const
{
	return cells[index].getEra();
}
Climate Zoo::getClimateAt(int index) const
{
	return cells[index].getClimate();
}
Dino Zoo::getDinoAt(int i, int j) const
{
	return cells[i].getDinoAt(j);
}
void Zoo::readFromFile(const char* filename)
{
	int cellsNum = 0;
	ifstream iFile(filename, ios::binary);
	iFile.read((char*)&cellsNum, sizeof(int));
	if (cellsNum == 0)
		return;
	Free();
	current = cellsNum;
	int grass, meat, fish;
	iFile.read((char*)&grass, sizeof(int));
	iFile.read((char*)&meat, sizeof(int));
	iFile.read((char*)&fish, sizeof(int));
	foodStorage[0] = grass;
	foodStorage[1] = meat;
	foodStorage[2] = fish;
	capacity = 2 * current;
	cells = new Cell[capacity];
	for (int i = 0; i < current; i++)
	{
		int size, freeSpace;
		Era era;
		Climate climate;
		iFile.read((char*)&size, sizeof(int));
		iFile.read((char*)&freeSpace, sizeof(int));
		iFile.read((char*)&era, sizeof(Era));
		iFile.read((char*)&climate, sizeof(Climate));
		Cell cell(climate, era, size);
		for (int j = 0; j < size - freeSpace; j++)
		{
			int nameLen, kindLen;
			bool array[4], is0, is1, is2, is3;
			Era dinoEra;
			Food food;
			Sex sex;

			iFile.read((char*)&nameLen, sizeof(int));
			char* name = new char[nameLen];
			iFile.read(name, sizeof(char) * nameLen);
			iFile.read((char*)&kindLen, sizeof(int));
			char* kind = new char[kindLen];
			iFile.read(kind, sizeof(char) * kindLen);

			iFile.read((char*)&dinoEra, sizeof(Era));
			iFile.read((char*)&food, sizeof(Food));
			iFile.read((char*)&sex, sizeof(Sex));
			iFile.read((char*)&is0, sizeof(bool));
			iFile.read((char*)&is1, sizeof(bool));
			iFile.read((char*)&is2, sizeof(bool));
			iFile.read((char*)&is3, sizeof(bool));
			array[0] = is0;
			array[1] = is1;
			array[2] = is2;
			array[3] = is3;
			Dino d(name, sex, dinoEra, kind, food, array);
			cell.addDino(d);
			delete[] name;
			delete[] kind;
		}
		cells[i] = cell;
	}
	iFile.close();
}