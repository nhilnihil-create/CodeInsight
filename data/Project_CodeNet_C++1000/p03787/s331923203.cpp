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

const int N = 1e5 + 100, OO = 100, T = 10, M = 100, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
vector <int> v[N];
int n, m, col[N], C[2];
bool bi;

void dfs(int x, bool c) {
	col[x] = c; 
	++C[c];
	for (int u : v[x]) {
		if (col[u] == -1) 
			dfs(u, !c);
		else if(col[x] == col[u])
			bi = false;
	}
}

int32_t main() {
	use_fast;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i = 1; i <= n; i++) 
		col[i] = -1;
	int d0 = 0, d1 = 0, d2 = 0;
	for(int i = 1; i <= n; i++) {
		if(col[i] == -1) {
			C[0] = C[1] = 0; 
			bi = true;
			dfs(i, 0);
			if(bi) {
				if(C[1]) 
					d2++;
				else 
					d0++;
			} 
			else d1++;
		}
	}
	cout << 2 * d0 * n - d0 * d0 + 2 * d2 * d1 + d1 * d1 + 2 * d2 * d2 << endl; 
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

