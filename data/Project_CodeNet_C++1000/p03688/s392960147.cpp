#include <bits/stdc++.h>
 
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define fo(i, a, b, k) for(int i = a; i <= b; i += k)
#define _fo(i, a, b, k) for(int i = a; i >= b; i -= k)
#define foa(i, a) for (auto &i : a)
#define fod(i, a) for(int i = 1; i*i <= a; i++)
#define sz(a) ((int) a.size())
#define all(a) begin(a), end(a)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mk(x, y) make_pair(x, y)  
#define log2i(x) (31-__builtin_clz(x))
#define log2ll(x) (63-__builtin_clzll(x)) 
#define msz(x) __builtin_popcount(x) 
#define mszll(x) __builtin_popcountll(x) 
#define fom(i, a, b) for(int i = a; i < (1<<b); i++)
#define ifon(i, mask) if(mask&(1<<i))
#define ss(i, mask) while(i=(i-mask)&mask)
#define ifss(i, mask) if(i > (mask^i)) 

int n, mn, mx, cnt;

bool solve() {
	if(mx-mn > 1) return false;
	if(mx-mn == 1) {
		int k = mx;
		if(cnt >= k) return false;
		return ((n-cnt) >= (k-cnt)*2);	
	}
	if(mx == mn) {
		if(mn == n-1) return true;
		return (n >= (mn)*2);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	mn = n;
	mx = 0;
	fo(i, 1, n, 1) {
		int val;
		cin >> val;
		
		if(val < mn) {
			cnt = 1;
			mn = val;
		}
		else if(val == mn) cnt++;
		
		mx = max(mx, val);
	}
	
	if(solve())	cout << "Yes";
	else cout << "No";
}