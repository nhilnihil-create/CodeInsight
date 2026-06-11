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
	ll n = 0, a, cnt = 1, ans = 0; cin >> n;
	vector<ll> v(n + 1);
	for (int h = 1; h <= n; h++) {
		cin >> v[h];
	}
	for (int h = 1; h <= n; h++) {
		if (v[v[h]] == h) { ans++; }
	}
	cout << ans / 2 << endl;
	cin >> n; return 0;
}