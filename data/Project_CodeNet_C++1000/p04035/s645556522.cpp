// ÐÐµ Ñ‚Ð¾Ñ‚ Ð²ÐµÐ»Ð¸Ðº, ÐºÑ‚Ð¾ Ð½Ð¸ÐºÐ¾Ð³Ð´Ð° Ð½Ðµ Ð¿Ð°Ð´Ð°Ð», Ð° Ñ‚Ð¾Ñ‚ Ð²ÐµÐ»Ð¸Ðº â€” ÐºÑ‚Ð¾ Ð¿Ð°Ð´Ð°Ð» Ð¸ Ð²ÑÑ‚Ð°Ð²Ð°Ð»!
// 0 <--> 100
#include <bits/stdc++.h>
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
                
//#define int long long
#define ll long long 
bool FLAG = 0;
#define debug(x) if (FLAG) {cerr << #x << " = " << x << endl;}
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

const int MOD = (int)1e9 + 7, N = (int)1e6+ 222;
const ll INF = (ll)1e18;

int n, L, a[N], sum;

void solve () {
	cin >> n >> L;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; ++i) {
		if (a[i] + a[i + 1] >= L) {
			cout << "Possible" << endl;
			for (int j = 1; j <= i - 1; ++j) cout << j << endl;
			for (int j = n - 1; j >= i + 1; --j) cout << j << endl;
			cout << i << endl;                                       
			return;
		}
	}
	cout << "Impossible";

}

signed main () {
	#ifdef Maga
		freopen("input", "r", stdin);
	#endif  
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);                                              
	int t = 1;
	while (t --) {
		solve ();
	}
	return 0;
}


