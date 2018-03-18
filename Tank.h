#pragma once
#include "Object.h"
class Tank :
	public Object
{
public:
	Tank(int x_pos,int y_pos, Owner own, Field *f, EventLoop *e);
	void move(int xDir, int yDir);
	void hide() override;
	void draw() override;
	void event() override;
	void tryDestroy(const Object* destroyer) override;
	void shoot();
	~Tank();
private:
	int xDirection;
	int yDirection;
	void genRandDir();
};