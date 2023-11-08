#include "Object.hpp"

void Object::Invoke() { 
	func(); 
}

Object::Object() { 
	_id = ID(); 
}

Object::Object(Object const& o) { 
	this->func = o.func; 
	this->id(o._id); 
}

int Object::ID() {
	static int id = 0;
	return id++;
}

int Object::id() const {
	return _id;
}

void Object::id(int id_) { 
	_id = id_; 
}

bool Object::operator==(Object o) const {
	return this->_id == o._id; 
}