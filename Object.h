#ifndef OBJECT_H
#define OBJECT_H
class Field;
class Object
{
public:
	enum Status { DESTROYED, NOT_DESTROYED };
	enum Owner { USER, COMPUTER };
	Object(Field *f, Owner own);
	virtual void move() = 0;
	virtual Status event() = 0;
	virtual void tryDestroy(const Object* destroyer) = 0;
	virtual void draw() = 0;
	virtual void hide() = 0;
	virtual ~Object() = default;
	Owner getOwner() const noexcept;
protected:
	Field * field;
	Owner owner;
	int x;
	int y;
};

#endif // !OBJECT_H
