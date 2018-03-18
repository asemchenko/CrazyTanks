#include "stdafx.h"
#include "EventLoop.h"
#include <Windows.h>
#include <stdexcept>

EventLoop::EventLoop()
{
}

void EventLoop::addObject(Object * o) {
	objects.push_back(o);
}

void EventLoop::start() {
	while (true)
	{
		objects.front()->event();
		Object *o = objects.front();
		objects.push_back(o);
		objects.pop_front();
		Sleep(10);
	}
}

void EventLoop::deleteObject(Object * o) {
	/*for (auto i = objects.begin(); i != objects.end(); ++i) {
		if (*i == o) {
			delete *i;
			objects.erase(i);
			break;
		}
	}*/
}


EventLoop::~EventLoop() {
	for (auto o : objects) {
		delete o;
	}
}
