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
	ll n, a, b, cnt = 1, ans = 0; cin >> n >> a >> b;
	if (a > b) { cout << 0 << endl; return 0; }
	if (n == 1) {
		if (a == b) { cout << 1 << endl; }
		else{ cout << 0 << endl; }
		return 0;
	}
	cnt = b - a;
	cout << cnt * (n - 2) + 1 << endl;
	cin >> n; return 0;
}