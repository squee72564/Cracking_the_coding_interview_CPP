#include <iostream>


void urlify(char *str, const int sz) {
	int space_count = 0, index = 0;
	for (int i = 0; i < sz; ++i) {
		if (str[i] == ' ') space_count++;
	}

	index = sz + space_count * 2;
	str[index] = '\0';
	for (int i = sz-1; i >= 0; --i) {
		if (str[i] == ' ' ) {
			str[index-1] = '0';
			str[index-2] = '2';
			str[index-3] = '%';
			index = index-3;
		} else {
			str[index-1] = str[i];
			index--;
		}
	}
}

int main() {
	char s1[255] = "Mr John Smith";

	urlify(s1, 13);

	std::cout << s1 << std::endl;

	return 0;
}
