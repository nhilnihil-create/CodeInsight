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
string s[110];
int co[30] = { 0 };
int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s[i];
		for (int j = 0; j < w; j++) {
			co[int(s[i][j] - 'a')]++;
		}
	}
	if (h % 2 == 0 && w % 2 == 0) {
		for (int i = 0; i < 26; i++) {
			if (co[i] % 4 != 0) {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
		return 0;
	}
	else if (h % 2 == 1 && w % 2 == 1) {
		bool b = false;
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			if (co[i] % 2 != 0) {
				if (b) {
					cout << "No" << endl;
					return 0;
				}
				b = true;
			}
			else if (co[i] % 4 != 0 && co[i] % 2 == 0) {
				int m = 1000000007;
				for (int j = 1; j <= 10100; j += 2) {
					if (co[i] % j == 0) {
						if (m > co[i] / j) {
							m = co[i] / j;
						}
					}
				}
				ans += m;
			}
		}
		if (b && h + w - 2 >= ans) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		return 0;
	}
	else {
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			if (co[i] % 2 != 0) {
				cout << "No" << endl;
				return 0;
			}
			if (co[i] % 4 != 0 && co[i] % 2 == 0) {
				int m = 1000000007;
				for (int j = 1; j <= 10100; j += 2) {
					if (co[i] % j == 0) {
						if (m > co[i] / j) {
							m = co[i] / j;
						}
					}
				}
				ans += m;
			}
		}
		int ans1;
		if (h % 2 == 0) {
			ans1 = h;
		}
		else {
			ans1 = w;
		}
		if (ans1 >= ans) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
