#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int H, W; cin >> H >> W;
	map<char, int> cnt;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char a; cin >> a;
			cnt[a]++;
		}
	}

	int four = 0, two = 0, one = 0;
	for (auto x : cnt) {
		if (x.second % 4 == 0)four++;
		else if (x.second % 2 == 0)two++;
		else one++;
	}

	bool flag = true;
	if (H % 2 == 0 && W % 2 == 0) {
		if (two >= 1 || one >= 1)flag = false;
	}
	if (H % 2 == 0 && W % 2 == 1) {
		if (two > H/2 || one >= 1)flag = false;
	}
	if (H % 2 == 1 && W % 2 == 0) {
		if (two > W/2 || one >= 1)flag = false;
	}
	if (H % 2 == 1 && W % 2 == 1) {
		if (two > (H+W)/2-1 || one >= 2)flag = false;
	}

	if (flag)cout << "Yes" << endl;
	else cout << "No" << endl;
}
