// tankTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include "Field.h"
int main()
{
	Field f(120, 28);
	f.draw();
	return 0;
}

