#pragma once
#include "Object.h"
class Bullet :
	public Object
{
public:
	Bullet(Field * f, Owner o, int xPos, int yPos, int xDir, int yDir);
	void move();
	Status event();
	void tryDestroy(const Object* destroyer);
	void draw();
	void hide();
private:
	int xDirection;
	int yDirection;
};

