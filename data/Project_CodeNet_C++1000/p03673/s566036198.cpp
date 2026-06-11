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
const ll INF = 10000000000000000;
const ll mod = 1000000007;
signed main() {
	ll n, a, cnt = 0, ans = 0; cin >> n;
	vector<ll> v(n), cost(n);
	for (int h = 0; h < n; h++) {
		cin >> v[h];
	}
	for (int h = n - 1; h >= 0; h -= 2) {
		if (h == n - 1) { cout << v[h]; }
		else { cout << ' ' << v[h]; }
	}
	if (n % 2 == 0) {
		for (int h = 0; h < n; h += 2) {
			cout << ' ' << v[h];
		}
	}
	else {
		for (int h = 1; h < n; h += 2) {
			cout << ' ' << v[h];
		}
	}
	cout << endl;
	cin >> n; return 0;
}