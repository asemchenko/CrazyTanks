#ifndef FIELED_H
#define FIELED_H

#include <vector>
#include "Object.h"
class Field
{
public:
	Field(int w, int h);
	Object* getObj(int xCoord, int yCoord);
	bool isEmpty(int xCoord, int yCoord);
	void freeCell(int xCoord, int yCoord);
	void captureCell(int xCoord, int yCoord, Object *o);
	void generateWalls(int count);
	void draw() const;
private:
	void drawHorizontalLine(int) const;
	int width;
	int height;
	int x;
	int y;
	std::vector<std::vector<Object*>> cells;
	std::vector<Object*> walls;
};

#endif // !FIELED_H