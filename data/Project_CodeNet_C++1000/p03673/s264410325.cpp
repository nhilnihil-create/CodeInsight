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
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
ll test[12345678], res[12345678];
signed main() {
	map<ll, ll> cost;
	ll n, m, a, b, c, x, cnt = 0, ans = 0; string s, t, u;
	cin >> n; vector<ll> v(n);
	for (int h = 0; h < n; h++) {
		cin >> v[h];
	}
	if (n % 2 == 0) {
		for (int h = n - 1; h >= 0; h -= 2) {
			if (h == n - 1) { cout << v[h]; }
			else { cout << ' ' << v[h]; }
		}
		for (int h = 0; h < n; h += 2) {
			cout << ' ' << v[h];
		}
		cout << endl;
	}
	else {
		for (int h = n - 1; h >= 0; h -= 2) {
			if (h == n - 1) { cout << v[h]; }
			else { cout << ' ' << v[h]; }
		}
		for (int h = 1; h < n; h += 2) {
			cout << ' ' << v[h];
		}
		cout << endl;
	}
	return 0;
}