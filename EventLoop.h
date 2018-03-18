#include <vector>
#include <list>
#include "Object.h"
class EventLoop
{
public:
	EventLoop();
	void addObject(Object * o);
	void start();
	void deleteObject(Object *o);
	~EventLoop();
private:
	std::list<Object*> objects;
};

