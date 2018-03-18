#include "stdafx.h"
#include "Field.h"
#include "Cursor.h"
#include "Wall.h"

Field::Field(int w, int h)
{
	width = w;
	height = h;
	x = 0;
	y = 0;
	// initializing matrix with nullptr
	cells.resize(height);
	for (int i = 0; i < height; i++)
	{
		cells[i].resize(width, nullptr);
	}
	// creating main wall
	walls.push_back(new Wall(this, nullptr));
	for (int i = 0; i < width; i++)
	{
		cells[height-1][i] = cells[0][i] = walls.front();

	}
	for (int i = 0; i < height; i++)
	{
		cells[i][0] = cells[i][width - 1] = walls.front();
	}
}

Object * Field::getObj(int xCoord, int yCoord)
{
	try {
		return cells.at(yCoord).at(xCoord);
	}
	catch (const std::out_of_range &e) {
		return nullptr;
	}
}

bool Field::isEmpty(int xCoord, int yCoord)
{
	return !static_cast<bool>(getObj(xCoord,yCoord));
}

void Field::freeCell(int xCoord, int yCoord)
{
	cells[yCoord][xCoord] = nullptr;
}

void Field::captureCell(int xCoord, int yCoord, Object * o)
{
	cells[yCoord][xCoord] = o;
}

void Field::generateWalls(int count) {
	for (int i = 0; i < count; i++)
	{
		walls.push_back(new Wall(rand() % (width - 10), rand() % (height - 10), rand() % 10 + 1, rand() % 2 + 1, this, nullptr));
		walls.back()->draw();
	}
}

void Field::draw() const
{
	setCursor(x, y);
	printf("%c", 201);
	drawHorizontalLine(width - 2);
	printf("%c\n", (187));
	for (int i = 0; i < height-1; i++)
	{
		printf("%c", (186));
		for (int j = 0; j < width - 2; j++)
		{
			printf(" ");
		}
		printf("%c\n", (186));
	}
	printf("%c", (char)200);
	drawHorizontalLine(width - 2);
	printf("%c\n", (char)188);
}


void Field::drawHorizontalLine(int length) const
{
	for (int i = 0; i < length; i++)
	{
		printf("%c", (205));
	}
}
