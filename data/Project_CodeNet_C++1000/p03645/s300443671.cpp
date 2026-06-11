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
ll test[12345678];
signed main() {
	ll n, m, k, l, cnt = 0, z = 0; cin >> n >> m;
	for (int h = 0; h < m; h++) {
		cin >> k >> l;
		if (test[l] != 0 && k == 1) { cout << "POSSIBLE" << endl; return 0; }
		if (test[k] != 0 && l == n) { cout << "POSSIBLE" << endl; return 0; }
		if (k == 1) { test[l]++; }
		if (l == n) { test[k]++; }
	}
	cout << "IMPOSSIBLE" << endl;
	cin >> n; return 0;
}