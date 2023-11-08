#pragma once
#ifndef __OBJECT
#define __OBJECT
#include <functional>
class Object {
public:
	void Invoke();
	Object();
	Object(Object const& o);
	static int ID();
	int id() const;
	void id(int id_);
	bool operator==(Object o) const;
private:
	int _id = -1;
protected:
	std::function<void()> func;
};
#endif // !__OBJECT
