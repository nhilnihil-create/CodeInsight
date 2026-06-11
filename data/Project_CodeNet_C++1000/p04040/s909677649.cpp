#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<ll, char> pc; 

const ll Mod = 1e9 + 7;
const ll Delta = 10889;
const int Maxn = 2e5 + 10;
const int Maxm = 1e3 + 10;
const ll Inf = 1e16;

ll f[Maxn], iv[Maxn];

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll pw = b, j = 1; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}
ll nCr(ll n, ll r){
	if((r < 0) || (n < r)) return 0;
	return mul(f[n], mul(iv[r], iv[n - r]));
}
ll solve(ll a, ll b){
	//cerr << a << " " << b << " " << nCr(a + b - 2, a - 1) << '\n';
	return nCr(a + b - 2, a - 1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	f[0] = 1; iv[0] = 1;
	for(int i = 1; i < Maxn; i++) f[i] = mul(f[i - 1], i), iv[i] = inv(f[i]);
	ll h, w, a, b;
	cin >> h >> w >> a >> b;
	ll ans = 0;
	for(int i = 1; i <= h - a; i ++){
		ans += mul(solve(i, b), solve(w - b, h - i + 1));
		ans %= Mod;
	}
	cout << ans;
	return 0;
}

