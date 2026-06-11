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

const int N = 3e5 + 100, OO = 1e16, T = 4500 + 100, M = 1e9 + 7, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int a[N];
vector <int> v[N];

int dfs(int x, int y) {
	vector <int> t;
	int sum = 0, num = 0, cnt = 0;
	for(auto u : v[x]) {
		if(u == y)
			continue;
		t.pb(dfs(u, x));
		sum += t.back();
		num += t.back();
	}
	int z = 2 * a[x] - sum;
	if((int)v[x].size() == 1)
		return a[x];
	sort(t.begin(), t.end());
	if(sum % 2 == 1)
		t[(int)t.size() - 1]--, sum--;
	sort(t.begin(), t.end());
	sum -= t.back();
	if(sum < t.back())
		cnt = sum;
	else
		cnt = (sum + t.back()) / 2;
	if(a[x] - z < 0 || cnt < (a[x] - z)) {
		cout << "NO" << endl;
		exit(0);
	}
	return z;
}

int32_t main() {
	use_fast;
	int n, rt = 1;
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
 	for(int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
		if((int)v[x].size() > 1)
			rt = x;
		if((int)v[y].size() > 1)
			rt = y;
	}
	if(n == 2) {
		if(a[1] != a[2])
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		return 0;
	}
	if(!dfs(rt, 0)) 
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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

