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

typedef int64_t ll;

const int N = 2e5+1;

ll n, k, s;
ll a[N], bit[N];
map<ll, int> id;

void update(int p) {
	while(p <= s) {
		bit[p]++;
		p += p&(-p);
	}
}

int get(int p) {
	int curr = 0;
	while(p > 0) {
		curr += bit[p];
		p -= p&(-p);
	}
	
	return curr;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll sum, ans = 0;
	
	sum = 0;
	cin >> n >> k;
	fo(i, 1, n, 1) {
		cin >> a[i];
		sum += (a[i]-k);
		id.insert({sum, 0});	
	}
	s = sz(id);
	
	int cnt = 1;
	foa(i, id) {
		i.se = cnt;
		cnt++; 
	}
	
	sum = 0;
	fo(i, 1, n, 1) {
		sum += (a[i]-k);
		int temp = id[sum];
		ans += (sum >= 0) + get(temp);
		update(temp);
	}
	
	cout << ans;
}