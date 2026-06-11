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
	vector<ll> v; map<ll, ll> cost;
	ll n, m, a, b, c, x, cnt = 0, ans = 0; string s, t, u;
	cin >> s >> t >> u;
	if (s[s.size() - 1] == t[0] && t[t.size() - 1] == u[0]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}