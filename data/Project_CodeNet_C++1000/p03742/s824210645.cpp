#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin() , v.end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, ans = 0, w, l;
vl A;
void input() {
	cin >> x >> y;
}
void solve() {	
	if (fabsl(x - y) < 2)cout << "Brown" << endl;
	else cout << "Alice" << endl;
}

int main() {
	input();
	solve();
}