#include <iostream>
#include <cmath>

bool replace(std::string& s1, std::string s2) {
	bool found_diff = false;

	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i]) {
			if (found_diff) return false;
			found_diff = true;
		}
	}

	return true;
}

bool insert(std::string& s1, std::string& s2) {
	int idx_1 = 0;
	int idx_2 = 0;

	while (idx_1 < s1.size() && idx_2 < s2.size()) {
		if (s1[idx_1] != s2[idx_2]) {
			if (idx_1 != idx_2) return false;	
			idx_2++;
		} else {
			idx_1++;
			idx_2++;
		}
	}
}

bool isOneAway(std::string &s1, std::string& s2) {
	if (s1.size() == s2.size()) {
		return replace(s1,s2);
	} else if (s1.size() + 1 == s2.size()) {
		return insert(s1,s2);
	} else if (s1.size() - 1 == s2.size()) {
		return insert(s2,s1);
	}

	return false;
}

int main() {
	

	return 0;
}
