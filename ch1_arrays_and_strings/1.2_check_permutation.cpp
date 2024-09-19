#include <iostream>
#include <string>
#include <algorithm>

// O(nlogn)
//bool isPermutation(std::string s1, std::string s2) {
//	if (s1.size() != s2.size()) return false;
//
//	std::sort(s1.begin(), s1.end());
//	std::sort(s2.begin(), s2.end());
//
//	return (s1 == s2);
//}

// O(n)
//bool isPermutation(const std::string& s1, const std::string& s2) {
//	if (s1.size() != s2.size())
//		return false;
//
//	int char_count[128] = {0};
//
//	for (const char c : s1) {
//		char_count[c]++;
//	}
//
//	for (const char c : s2) {
//		char_count[c]--;
//		if (char_count < 0) return false;
//	}
//
//	return true;
//
//}

int main() {
	std::string s1 = "abc";
	std::string s2 = "cba";
	std::string s3 = "dba";

	if (isPermutation(s1, s2)) {
		std::cout << s1 << "==" << s2 << "\n";
	}

	if (isPermutation(s1, s3)) {
		std::cout << s1 << "==" << s2 << "\n";
	}

	return 0;
}
