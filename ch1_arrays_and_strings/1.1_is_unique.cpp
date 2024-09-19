#include <string>
#include <iostream>

bool isUnique(std::string& str) {
	if (str.size() > 128) return false;

	bool char_set[128] = {false};

	for (const char c : str) {
		// optionally skip space
		if (c == ' ') continue;
		if (char_set[c]) return false;
		char_set[c] = true;
	}

	return true;
}

int main() {
	std::string s1 = "This does not have all unique characters.";
	std::string s2 = "Sphinx judge my vow!";

	if (isUnique(s1)) {
		std::cout << s1 << std::endl;
	}

	if (isUnique(s2)) {
		std::cout << s2 << std::endl;
	}

	return 0;
}
