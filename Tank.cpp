#include "stdafx.h"
#include "Tank.h"
#include "Cursor.h"
#include "Field.h"
#include "Bullet.h"
#include "EventLoop.h"
#include <cstdlib>
#include <conio.h>


Tank::Tank(int x_pos, int y_pos, Owner own, Field * f, EventLoop *e): Object(f,own, e)
{
	x = x_pos;
	y = y_pos;
	genRandDir();
	draw();
}

void Tank::move(int xDir, int yDir)
{
	if (field->isEmpty(x + xDir, y + yDir)) {
		field->captureCell(x + xDir, y + yDir, static_cast<Object*>(this));
		field->freeCell(x, y);
		hide();
		x += xDir;
		y += yDir;
		draw();
	}
	xDirection = xDir;
	yDirection = yDir;
}


void Tank::hide()
{
	setCursor(x, y);
	printf(" ");
}

void Tank::draw() {
	setCursor(x, y);
	printf("%c",(char)254);
}

void Tank::event() {
	if (owner == COMPUTER) {
		if (rand() % 3 == 0) {
			genRandDir();
		}
		move(xDirection, yDirection);
		if (rand() % 15 == 0) {
			shoot();
		}
	}
	else {
		if (kbhit()) {
			xDirection = 0;
			yDirection = 0;
			char c = getch();
			switch (c)
			{
				case 72:
					yDirection = -1;
					break;
				case 77:
					xDirection = 1;
					break;
				case 75:
					xDirection = -1;
					break;
				case 80:
					yDirection = 1;
					break;
				default:
					break;
			}
		}
		else {
			xDirection = 0;
			yDirection = 0;
		}
		if (xDirection || yDirection) {
			move(xDirection, yDirection);
		}
	}
}

void Tank::tryDestroy(const Object * destroyer) {
	if (destroyer->getOwner() != owner) {
		// calling autoDestroyer
	}
}

void Tank::shoot() {
	Bullet *b = new Bullet(field, owner, eventLoop, x, y, xDirection, yDirection);
	eventLoop->addObject(b);
}


Tank::~Tank() {
	hide();
	field->freeCell(x, y);
}

void Tank::genRandDir() {
	xDirection = (rand() % 3) - 1;
	if (!xDirection) {
		yDirection = rand() % 2 ? 1 : -1;
	} else {
		yDirection = 0;
	}
}
