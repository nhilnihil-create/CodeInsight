#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	string s;
	cin >> s;
	int start;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			start = i;
			break;
		}
	}
	int end;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'Z') {
			end = i;
			break;
		}
	}
	printf("%d\n", end - start + 1);
	return 0;
}
