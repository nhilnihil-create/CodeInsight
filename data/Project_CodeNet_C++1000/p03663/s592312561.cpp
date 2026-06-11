#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;
//#define int long long
void check(string cur) {
	string sav = cur;
	reverse(cur.begin(), cur.end());
	int p = 1;
	for (int i = 0; i < cur.size(); ++i) {
		if (!p) continue;
		if (cur[i] != '9') {
			cur[i]++;
			p = 0;
		}
		else cur[i] = '0';
	}
	if (p) cur.push_back('1');
	reverse(cur.begin(), cur.end());
	cout << "? " << cur << endl;
	char ans;
	cin >> ans;
	if ((p && ans == 'N') || (!p && ans == 'Y')) {
		cout << '!' << ' ' << sav << endl;
		exit(0);
	}
}
signed main() {
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	string znaem = "";
	while (true) {
		if (znaem != "") {
			check(znaem);
		}
		int bot = znaem.size() ? -1 : 0;
		int top = 9;
		while (top > bot + 1) {
			int mid = (bot + top) / 2;
			string cur = znaem;
			cur += mid + '0';
			while (cur.size() != 15) cur.push_back('9');
			cout << "? " << cur << endl;
			char ans;
			cin >> ans;
			if (ans == 'N') {
				bot = mid;
			}
			else {
				top = mid;
			}
		}
		znaem += bot + '1';
	}
}