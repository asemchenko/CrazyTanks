#pragma once
#include "Object.h"
#include "EventLoop.h"
#include "Field.h"
class Wall :
	public Object
{
public:
	Wall(int xPos, int yPos, int h, int w, Field *f, EventLoop *e);
	Wall(Field *f, EventLoop *e);
	virtual void tryDestroy(const Object* destroyer);
	virtual void draw();
	virtual void hide();
	~Wall();
private:
	int width;
	int height;
};

