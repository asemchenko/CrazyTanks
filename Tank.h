#pragma once
#include "Object.h"
class Tank :
	public Object
{
public:
	Tank(int,int);
	virtual void move() override;
	~Tank();
};

