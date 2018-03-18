#include "stdafx.h"
#include "Wall.h"
#include "Cursor.h"
#include "Field.h"

Wall::Wall(int xPos, int yPos, int h, int w, Field * f, EventLoop * e) : Object(f, Object::COMPUTER, e) {
	x = xPos;
	y = yPos;
	height = h;
	width = w;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field->captureCell(x + i, y + j, this);
		}
	}
}

Wall::Wall(Field * f, EventLoop * e): Object(f, Object::COMPUTER, e) {
	width = 0;
	height = 0;
	x = 0;
	y = 0;
}

void Wall::tryDestroy(const Object * destroyer)
{
}

void Wall::draw() {
	for (int i = 0; i < height; i++)
	{
		setCursor(x + i, y);
		for (int j = 0; j < width; j++)
		{
			printf("%c", (char)219);
		}
	}
}
void Wall::hide() {
	for (int i = 0; i < height; i++)
	{
		setCursor(x + i, y);
		for (int j = 0; j < width; j++)
		{
			printf(" ");
		}
	}
}
Wall::~Wall() {
	hide();
}