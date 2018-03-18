#ifndef OBJECT_H
#define OBJECT_H
class Field;
class EventLoop;
class Object
{
public:
	enum Status { DESTROYED, NOT_DESTROYED };
	enum Owner { USER, COMPUTER };
	Object(Field *f, Owner own, EventLoop *e);
	virtual void move();
	virtual void event();
	virtual void tryDestroy(const Object* destroyer) = 0;
	virtual void draw() = 0;
	virtual void hide() = 0;
	virtual ~Object() = default;
	Owner getOwner() const noexcept;
protected:
	Field * field;
	EventLoop *eventLoop;
	Owner owner;
	int x;
	int y;
};

#endif // !OBJECT_H
