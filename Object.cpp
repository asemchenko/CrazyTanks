#include "stdafx.h"
#include "Object.h"

Object::Object(Field * f, Owner own): field(f), owner(own) {
}

Object::Owner Object::getOwner() const noexcept
{
	return owner;
}
