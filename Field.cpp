#include "stdafx.h"
#include "Field.h"
#include "Cursor.h"


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
	// ONLY FOR DEBUG
	for (int i = 0; i < width; i++)	{
		cells[0][i] = cells[height - 1][i] = (Object*)123;
	}
	for (int i = 0; i < height; i++)
	{
		cells[i][0] = cells[i][width - 1] = (Object*)123;
	}
}

Object * Field::getObj(int xCoord, int yCoord)
{
	return cells[yCoord][xCoord];
}

bool Field::isEmpty(int xCoord, int yCoord)
{
	return !static_cast<bool>(cells[yCoord][xCoord]);
}

void Field::freeCell(int xCoord, int yCoord)
{
	cells[yCoord][xCoord] = nullptr;
}

void Field::captureCell(int xCoord, int yCoord, Object * o)
{
	cells[yCoord][xCoord] = o;
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
