#include "stdafx.h"
#include "Field.h"
#include "Cursor.h"


Field::Field(int w, int h)
{
	width = w;
	height = h;
	x = 0;
	y = 0;
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

void Field::addObject(Object * o)
{
	objects.push_back(o);
}

Field::~Field()
{
	for (auto o : objects) {
		delete o;
	}
}

void Field::drawHorizontalLine(int length) const
{
	for (int i = 0; i < length; i++)
	{
		printf("%c", (205));
	}
}
