#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[12345678], ok[12345678];
signed main() {
	int n, a, cnt = 0, sum = 0, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a; test[h] = a; cnt += a; sum += h + 1;
		if (h == 0) { test[n] = a; }
	}
	if (cnt % sum != 0) { cout << "NO" << endl; return 0; }
	cnt /= sum;
	for (int h = 0; h < n; h++) {
		if (test[h + 1] - test[h] != cnt) {
			int ok = test[h] + cnt;
			while (true) {
				ok -= n; ans++;
				if (ok == test[h + 1]) { break; }
				if (ok < test[h + 1]) { cout << "NO" << endl; return 0; }
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}