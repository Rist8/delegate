#include <iostream>
#include "Delegate.hpp"

void Print(std::string s) {
	std::cout << s;
}

void Pointless(int i, char c, double d, float f,
	std::string s) {
	printf("%i %c %f %f %s", i, c, d, f, s.c_str());
}

int main() {
	Delegate deleg;
	Method<std::string> func([](std::string s) { std::cout << s; },
		std::string("Hello world!\n"));
	deleg += func;
	deleg += Method<>([]() { std::cout << "Hi"; });
	deleg.Invoke();
	Method func1(Pointless, 1, 'c', 2.4, 0.1f, std::string("abc\n"));
	deleg += func1;
	deleg.Invoke();
}