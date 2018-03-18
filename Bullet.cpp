#include "stdafx.h"
#include "Bullet.h"
#include "Field.h"
#include "Cursor.h"


Bullet::Bullet(Field * f, Owner o, int xPos, int yPos, int xDir, int yDir)
	: Object(f,o){
	xDirection = xDir;
	yDirection = yDir;
	x = xPos+xDir;
	y = yPos + yDir;
	if (field->isEmpty(x, y)) {
		field->captureCell(x, y, this);
	}
	else {
		field->getObj(x, y)->tryDestroy(this);
		hide();
	}
}

void Bullet::move()
{
	if (field->isEmpty(x+xDirection, y+yDirection)) {
		field->captureCell(x + xDirection, y + yDirection, this);
		hide();
		field->freeCell(x, y);
		x += xDirection;
		y += yDirection;
		draw();
	}
	else {
		field->getObj(x, y)->tryDestroy(this);
		hide();
	}
}

Object::Status Bullet::event()
{
	return Status();
}

void Bullet::tryDestroy(const Object * destroyer){
	// delete this
}

void Bullet::draw(){
	setCursor(x, y);
	printf("%c", (char)253);
}

void Bullet::hide(){
	setCursor(x, y);
	printf(" ");
}
