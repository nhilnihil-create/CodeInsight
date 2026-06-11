#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	string s;
	cin >> s;
	string s1 = s;
	int min = 1000000007;
	for (int i = 0; i < s.size(); i++) {
		int co = 0;
		for (;;) {
			int co1 = 0;
			for (int k = 0; k < s.size() - co; k++) {
				if (s[k] == s1[i]) {
					co1++;
				}
			}
			if (co1 == s.size() - co) {
				if (co < min) {
					min = co;
				}
				s = s1;
				break;
			}
			co++;
			for (int j = 0; j < s.size() - co; j++) {
				if (s[j] == s1[i] || s[j + 1] == s1[i]) {
					s[j] = s1[i];
				}
			}
		}
	}
	cout << min << endl;
	return 0;
}