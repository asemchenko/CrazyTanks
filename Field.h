#pragma once
#include "Object.h"
#include <vector>
class Field
{
public:
	Field(int w, int h);
	void draw() const;
	void addObject(Object *o);
	~Field();
private:
	void drawHorizontalLine(int) const;
	int width;
	int height;
	int x;
	int y;
	std::vector<Object*> objects;
};

