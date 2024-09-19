#include <iostream>
#include <string>

std::string compress_string(const std::string& s) {
	std::string ret = "";
	int count = 0;

	for (int i = 0; i < s.size(); ++i) {
		count++;
		if (i+1 >= s.size() || s[i] != s[i+1]) {
			ret += s[i] + std::to_string(count);

			count = 0;
		}

	}

	return (ret.size() < s.size()) ? ret : s;
}

int main() {
	std::string s1 = "aabcccccaaa";
	std::string s2 = compress_string(s1); 

	std::cout << s1 << " : " << s2 << std::endl;
	return 0;
}
