#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <algorithm>
using std::string;

string s, s1;
int len = 0;

int main() {
	std::cin >> s;
	s1 = s;
	len = s.size();
	for (int i = 0, j = len - 1; i < j; ++i, --j) {
		std::swap(s[i], s[j]);
	}
	for(int i = 0; i < len; ++i) {
		if (s[i] == 'd') {
			s[i] = 'b';
		}
		else if (s[i] == 'b') {
			s[i] = 'd';
		}
		else if (s[i] == 'q') {
			s[i] = 'p';
		}
		else if (s[i] == 'p') {
			s[i] = 'q';
		}
	}
	if (s1 == s) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}