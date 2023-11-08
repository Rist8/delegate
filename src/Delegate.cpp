#include "Delegate.hpp"

void Delegate::Invoke() {
	for (Object* n : functions)
		n->Invoke();
}

size_t Delegate::AddListener(Object& func) {
	if (std::find(functions.begin(), functions.end(), &func) == functions.end())
		functions.push_back(new Object(func));
	return functions.size() - 1;
}

size_t Delegate::AddListener(Object& func, size_t pos) {
	if (std::find(functions.begin(), functions.end(), &func) == functions.end())
		functions.insert(functions.begin() + pos, new Object(func));
	return pos;
}

bool Delegate::RemoveListener(Object& func) {
	size_t i;
	for (i = 0; i < functions.size(); ++i)
		if (*functions[i] == func)
			break;
	if (functions.begin() + i != functions.end()) {
		delete functions[i];
		functions.erase(functions.begin() + i);
		return true;
	}
	return false;
}

bool Delegate::RemoveListener(size_t pos) {
	if (pos < functions.size()) {
		delete functions[pos];
		functions.erase(functions.begin() + pos);
		return true;
	}
	return false;
}

bool Delegate::RemoveLast() {
	if (functions.size() > 0)
		if (RemoveListener(functions.size() - 1))
			return true;
	return false;
}

std::vector<int> Delegate::GetIds() {
	std::vector<int> result;
	for (size_t i = 0; i < functions.size(); ++i)
		result.push_back(functions[i]->id());
	return result;
}

size_t Delegate::ListenersCount() {
	return functions.size();
}