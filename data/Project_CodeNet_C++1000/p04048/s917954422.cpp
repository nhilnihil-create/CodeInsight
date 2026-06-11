#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 5050, mod = 1e9 + 7;
ll solve(ll n, ll x) {
	if(x == 0 || x == n) return 0;
	ll l = n-x;
	ll cnt = x / l;
	ll ans = 3*l*cnt;
	x %= l;
	if(x) ans += l + 2*x;
	return ans + solve(l, (l-x)%l) - ((l-x)%l);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, x;
	cin >> n >> x;
	cout << solve(n, x); 
}
