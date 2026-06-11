#include <bits/stdc++.h>
//<(") 
#define ll long long  
using namespace std;
 
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
 
const ll mod = 1e9 + 7;
const ll siz = 2e5 + 10;
const ll base = 32;
const ll MAXX = 1e9;

ll n, k, l;
vector<ll> hold;
vector<ll> nxt;

void compress() {
	sort(nxt.begin(), nxt.end());
	l = unique(nxt.begin(), nxt.end()) - nxt.begin();
	nxt.resize(l);
	for (ll i = 1; i <= n; i++) {
		hold[i] = lower_bound(nxt.begin(), nxt.end(), hold[i]) - nxt.begin() + 1;
	}
}

ll tree[siz];

void update(ll node, ll val) {
	for (ll i = node; i <= l; i += i & -i) {
		tree[i] += val;
	}
}

ll get(ll node) {
	ll ans = 0;
	for (ll i = node; i; i -= i & -i) {
		ans += tree[i];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("INP.txt", "r", stdin);
	//freopen("OUT.txt", "w", stdout);
	cin >> n >> k;
	hold.resize(n + 1);
	nxt.push_back(0);
	for (ll i = 1; i <= n; i++) {
		cin >> hold[i];
		hold[i] -= k;
		hold[i] += hold[i - 1];
		//cerr << hold[i] << ' ';
		nxt.push_back(hold[i]);
	}
	//cerr << '\n';
	compress();
	for (ll i = 1; i <= n; i++) {
		cerr << hold[i] << ' ';
	}
	//cerr << '\n';
	update(lower_bound(nxt.begin(), nxt.end(), 0) - nxt.begin() + 1, 1);
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ans += get(hold[i]);
		//cerr << get(hold[i]) << ' ';
		update(hold[i], 1);
	}	
	//cerr << '\n';
	cout << ans << '\n';
	return 0;
}  	 	   		  		 		 	  			  		