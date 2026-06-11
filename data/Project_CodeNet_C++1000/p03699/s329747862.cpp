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
ll test[1234][1234];
signed main() {
	ll n = 0, a, mae = 0, ans = 0; cin >> n;
	vector<ll> v(n);
	for (int h = 0; h < n; h++) {
		cin >> v[h]; ans += v[h];
	}
	sort(v.begin(), v.end());
	if (ans % 10 != 0) { cout << ans << endl; return 0; }
	for (int h = 0; h < n; h++) {
		if (v[h] % 10 != 0) { ans -= v[h]; cout << ans << endl; return 0; }
	}
	cout << 0 << endl;
	cin >> n; return 0;
}