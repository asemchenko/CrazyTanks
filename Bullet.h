#pragma once
#include "Object.h"
class Bullet :
	public Object
{
public:
	Bullet(Field * f, Owner o, EventLoop *e, int xPos, int yPos, int xDir, int yDir);
	void move();
	void tryDestroy(const Object* destroyer);
	void draw();
	void hide();
	~Bullet();
private:
	int xDirection;
	int yDirection;
};

