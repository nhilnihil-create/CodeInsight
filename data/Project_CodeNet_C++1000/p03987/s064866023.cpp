//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
 
//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <bitset> 
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
                
#define int long long
#define ll long long 
bool FLAG = 0;
#define debug(x) if (FLAG) { 	cerr << #x << " = " << x << endl;}
#define debug_vec(x) if (FLAG) {cerr << #x << " = {"; for (auto to x) cout << to << ", "; cout << "}" << endl}
#define F first
#define S second                               
#define sqr(x) ((x) * (x))
#define make make_pair
#define pb push_back
#define sz(x) (int)(x.size()) 
#define all(x) x.begin (), x.end ()
 
using namespace std;
                        
typedef unsigned long long ull;
typedef long double ld;
 
const int MOD = 998244353, N = (int)1e6+ 222;
const int INF = (int)1e18;
const ld eps = (ld)1e-6;
 
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};         
                 
int n, a[N], l[N], r[N];
 
 
inline void solve () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	a[n + 1] = -INF;
	stack <int> s;
	for (int i = 1; i <= n + 1; ++i) {
		while (!s.empty() && a[s.top()] > a[i]) {
			r[s.top()] = i - 1;
			s.pop();
		}
		s.push(i);
	}
	s.pop();
	a[0] = -INF;
	for (int i = n; i >= 0; --i) {
		while (!s.empty() && a[s.top()] > a[i]) {
			l[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (r[i] - i + 1) * (i - l[i] + 1) * a[i];		
	}
	cout << ans;
}	    
 
signed main () {
	#ifdef Maga
		freopen("input", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}