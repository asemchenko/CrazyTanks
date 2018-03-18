#include "stdafx.h"
#include "Object.h"

Object::Object(Field * f, Owner own, EventLoop *e): field(f), owner(own),
eventLoop(e) {}

void Object::move(){}

void Object::event() {
	return move();
}

Object::Owner Object::getOwner() const noexcept {
	return owner;
}
