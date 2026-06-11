//                             In The Name Of Allah                                           
//                             	Mohammad Hosseini
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 

const int N = 3e5 + 100, OO = 724249387, T = 1e6 + 100, M = 1e9 + 7, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;

vector <int> v[N];
int dfs(int x, int y, int d, int top) {
	int ans = 0;
	if(d <= top) 
		ans++;
	for(auto u : v[x]) 
		if(u != y) 
			ans += dfs(u, x, d + 1, top);
	return ans;
}

int32_t main() {
	use_fast;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int ans = 0;
	if(k % 2) {
		for(int i = 1; i <= n; ++i) {
			vector <int> tp, bt;
			for (int u : v[i]) {
				tp.pb(dfs(u, i, 1, k / 2 + 1));
				bt.pb(dfs(u, i, 1, k / 2));
			}
			int su = 0;
			for (int x : bt) 
				su += x;
			int in = 0;
			for(int i = 0; i < (int)tp.size(); i++) 
				in = max(in, tp[i] - bt[i]);
			ans = max(ans, in + su + 1);
		}
	}
	else {
		for (int i = 1; i <= n; ++i) {
			int h = 1;
			for (auto u : v[i]) 
				h += dfs(u, i, 1, k / 2);
			ans = max(ans, h);
		}
	}
	cout << n - ans << endl;
	return 0;
}
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- uploaded by ubuntu 20.04 
5- ...
*/
