#include <iostream>
#include <string>

bool isPalindromePermutation(const std::string& str) {
	int char_count[128] = {0};
	bool isOddFound = false;

	for (char c : str) {
		if (c == ' ') continue;
		if (c >= 65 && c <= 90) c = c+32;
		char_count[c]++;
	}

	for (int i = 0; i < 128; ++i) {
		if (char_count[i] % 2 != 0) {
			if (isOddFound) return false;
			isOddFound = true;
		}
	}

	return true;
}

int main() {

	std::string s1 = "dbbadcca";
	std::string s2 = "Tact Coa";

	if (isPalindromePermutation(s1)) {
		std::cout << s1 << " is a palindrome permutation!\n";
	}

	if (isPalindromePermutation(s2)) {
		std::cout << s2 << " is a palindrome permutation!\n";
	}

	return 0;
}
