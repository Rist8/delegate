#pragma once
#ifndef __METHOD
#define __METHOD
template <class... Args>
class Method : public Object {
public:
	Method() : Object() { }

	Method(Method<Args...> const& func) { this->id(func.id()), this->func = func.func; }

	Method(void(*f)(Args...), Args... _args) : Object() {
		this->func = std::bind(f, _args...);
	}

	void Initialise(void(*f)(Args...), Args... _args) {
		this->func = Method(f, std::move(_args...));
	}

};
#endif // !__METHOD

