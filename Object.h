#pragma once
class Object
{
public:
	Object() = default;
	virtual void move() = 0;
	virtual ~Object() = default;
protected:
	int x;
	int y;
};

