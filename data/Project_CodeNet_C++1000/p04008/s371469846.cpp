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

const int N = 3e5 + 100, OO = 724249387, T = 4500 + 100, M = 1e9 + 7, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int a[N], n, k, ans = 0;
vector <int> v[N];

int dfs(int x, int y) {
	int mx = 0;
	for(auto u : v[x]) 
		mx = max(dfs(u, x) + 1, mx);
	if(mx < k - 1)
		return mx;
	if(x != 1 && mx == k - 1) {
		if(y != 1)
			ans++;
		return -1;
	}
	return 0;
}

int32_t main() {
 	use_fast;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 2; i <= n; i++)
		v[a[i]].pb(i);
	dfs(1, 0);
	if(a[1] != 1)
		ans++;
	cout << ans  << endl;
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

