#pragma once
#ifndef __DELEGATE
#define __DELEGATE
#include "Object.hpp"
#include "Method.hpp"

class Delegate {
public:
	void Invoke();

	size_t AddListener(Object& func);
	size_t AddListener(Object& func, size_t pos);

	bool RemoveListener(Object& func);
	bool RemoveListener(size_t pos);

	bool RemoveLast();

	std::vector<int> GetIds();

	size_t ListenersCount();

	template <class... Args>
	void operator += (Method<Args...> func) {
		AddListener(func);
	}

	template <class... Args>
	void operator -= (Method<Args...> func) {
		RemoveListener(func);
	}

private:
	std::vector<Object*> functions;
};
#endif // !__DELEGATE
