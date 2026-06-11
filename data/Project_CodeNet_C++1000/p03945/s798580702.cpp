#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	string s;
	cin >> s;

	int countW = 0, countB = 0;
	for (size_t i = 1; i < s.length(); ++i) {
		if (s[i] != s[i - 1]) {
			if (s[i] == 'B') {
				countB++;
			}
			else {
				countW++;
			}
		}
	}
	
	cout << countB + countW << endl;
	return 0;
}