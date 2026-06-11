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
	int n;
	string s;
	string kl = "", kr = "";
	cin >> n >> s;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			l++;
		}
		else {
			if (l != 0) {
				l--;
			}
			else {
				r++;
			}
		}
	}
	for (int j = 0; j < l; j++) {
		kr += ")";
	}
	for (int j = 0; j < r; j++) {
		kl += "(";
	}
	l = 0, r = 0;
	cout << kl << s << kr << endl;
}