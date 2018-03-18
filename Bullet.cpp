#include "stdafx.h"
#include "Bullet.h"
#include "Field.h"
#include "EventLoop.h"
#include "Cursor.h"


Bullet::Bullet(Field * f, Owner o, EventLoop *e, int xPos, int yPos, int xDir, int yDir)
	: Object(f,o, e){
	xDirection = xDir;
	yDirection = yDir;
	x = xPos+xDir;
	y = yPos + yDir;
	if (field->isEmpty(x, y)) {
		field->captureCell(x, y, this);
	}
	else {
		field->getObj(x, y)->tryDestroy(this);
		tryDestroy(this);
	}
}

void Bullet::move()
{
	for (int i = 0; i < 1; i++)
	{
		if (field->isEmpty(x + xDirection, y + yDirection)) {
			field->captureCell(x + xDirection, y + yDirection, this);
			hide();
			field->freeCell(x, y);
			x += xDirection;
			y += yDirection;
			draw();
		}
		else {
			field->getObj(x, y)->tryDestroy(this);
			tryDestroy(this);
		}
	}
}


void Bullet::tryDestroy(const Object * destroyer){
	xDirection = 0;
	yDirection = 0;
	hide();
	eventLoop->deleteObject(this);
}

void Bullet::draw(){
	setCursor(x, y);
	printf("%c", (char)253);
}

void Bullet::hide(){
	setCursor(x, y);
	printf(" ");
}

Bullet::~Bullet() {
	hide();
	field->freeCell(x, y);
}
