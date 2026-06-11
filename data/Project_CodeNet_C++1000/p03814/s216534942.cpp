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
//printf("%.10f\n", n);
signed main() {
	ll n, m, a = 0, b = 0, cnt = 0, ans = 1; string s; cin >> s;
	for (int h = 0; h < s.size(); h++) {
		if (cnt == 0 && s[h] == 'A') { a = h; cnt++; }
		if (s[h] == 'Z' && b < h) { b = h; }
	}
	cout << b - a + 1 << endl;
	cin >> n; return 0;
}