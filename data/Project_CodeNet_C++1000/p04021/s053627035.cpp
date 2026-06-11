//                             In The Name Of Allah
#include <bits/stdc++.h>
#define ss second
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

const int N = 1e5 + 100, T = 2e3 + 100, OO = 1e12 + 10, M = 1e9 + 7, P = 49157, sq = 360, lg = 20;
typedef pair <int, int> pii;
vector <int> v;
int a[N];

int32_t main() {
	use_fast;
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	for(int i = 1; i <= n; i++) {
		int x = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
		if(x % 2 != i % 2)
			ans++;
	}
	cout << ans / 2 << endl;
	return 0;
} 	
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/