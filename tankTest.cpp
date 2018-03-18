// tankTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Field.h"
#include "Tank.h"
#include "Cursor.h"
#include "Bullet.h"
#include "EventLoop.h"
#include <Windows.h>

int main()
{
	hideCursor();
	srand(time(0));
	Field f(119, 28);
	EventLoop e;
	f.draw();
	Tank *t = new Tank(5,5,Object::USER, &f, &e);
	for (int i = 0; i < 3; i++)
	{
		e.addObject(new Tank(rand() % 100 + 5, rand() % 25 + 1, Object::COMPUTER, &f, &e));
	}
	e.addObject(t);
	e.start();
	system("pause");
	return 0;
}

