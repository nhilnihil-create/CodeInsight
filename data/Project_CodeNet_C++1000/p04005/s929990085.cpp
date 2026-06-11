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
#include<functional>
//#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
signed main() {
	ll n, a, b, c, cnt = 0, ans = 0;
	cin >> a >> b >> c;
	cnt = min(a, min(b, c)); ans = max(a, max(b, c));
	if (a % 2 != 0 && b % 2 != 0 && c % 2 != 0) {
		cout << cnt * (a + b + c - ans - cnt) << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}