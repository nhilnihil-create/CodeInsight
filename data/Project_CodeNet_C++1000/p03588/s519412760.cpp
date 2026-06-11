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
    ll n, m, a, b, cnt = 0, ans = 1; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a >> b;
		if (cnt < a) { cnt = a; ans = a + b; }
	}
	cout << ans << endl;
	cin >> n; return 0;
}