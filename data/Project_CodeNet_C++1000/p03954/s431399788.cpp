//                             In The Name Of Allah                                           
//                             	Mohammad Hosseini
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
//#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 

const int N = 3e5 + 100, OO = 1e9, T = 4500 + 100, M = 1e9 + 7, P = 6151, SQ = 280, lg = 30;
typedef pair <int, int> pii;
int a[N];

int32_t main() {
	use_fast;
	int n;
	cin >> n;
	for(int i = 1; i <= 2 * n - 1; i++) 
		cin >> a[i];
	vector <int> v = {a[n - 1], a[n], a[n + 1]};
	sort(v.begin(), v.end());
	int ans = v[1];
	if(n <= 2)
		return cout << ans << endl, 0;
	if(v[1] == a[n]) 
		return cout << ans << endl, 0;
	else if(v[2] == a[n]) {
		int l = v[1], r = v[2];
		for(int i = 2; i < n; i++) {
			if(l >= r)
				break;
			if(i % 2 == 1) {
				ans = max(ans, max(min(r, a[n - i]), min(r, a[n + i])));
				l = max(l, max(a[n - i], a[n + i]));
			}
			else 
				r = min(r, min(a[n - i], a[n + i]));
		}
		if(l < r && n % 2 == 1)
			ans = max(ans, r);
	}
	else {
		ans = v[0];
		int l = v[0], r = v[1];
		for(int i = 2; i < n; i++) {
			if(l >= r)
				break;
			if(i % 2 == 0) {
				ans = max(ans, max(min(r, a[n - i]), min(r, a[n + i])));
				l = max(l, max(a[n - i], a[n + i]));
			}
			else 
				r = min(r, min(a[n - i], a[n + i]));
		}
		if(l < r && n % 2 == 0)
			ans = max(ans, r);
	}
	cout << ans << endl;
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

