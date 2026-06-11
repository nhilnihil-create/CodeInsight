#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 202, mod = 119<<23|1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n;
ll c = 1;
vi suf, ans;

int count() {
	int a = 0;
	for(int i = 0; i < 1<<ans.size(); i++) {
		vi cur;
		for(int j = 0; j < ans.size(); j++) {
			if((i>>j)&1) cur.pb(ans[j]);
		}
		if(cur.size()&1) continue;
		int ok = 1;
		for(int i = 0; i + cur.size()/2 < cur.size(); i++)
			ok &= cur[i] == cur[i + cur.size()/2];
		a += ok;
	}
	return a;
}

const ll MOD = 1000000000000037, MAXA = 60;
ll mul(ll a, ll b) {
	return __int128(a)*b%MOD;
}
ll fact[MAXA], inv[MAXA];
void setup() {
	for(int i = 0; i < MAXA; i++) {
		inv[i] = i > 1 ? MOD - mul(MOD/i, inv[MOD%i]) : 1;
		fact[i] = i + (i == 0);
	}
	partial_sum(fact, fact + MAXA, fact, mul);
	partial_sum(inv, inv + MAXA, inv, mul);
}
ll nck(ll n, ll k) {
	return n >= k ? mul(fact[n], mul(inv[k], inv[n-k])) : 0;
}

ll get(ll n, ll k) {
	k = min(k, n-k);
	ll res = 0;
	for(int i = 0; i <= k; i++) {
		res += nck(n-k, i)*nck(k, i);
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	setup();
	cin >> n;
	n++; //empty string
	
	while((1ll<<c) <= n) c++;
	n -= 1ll<<(c-1);
	for(int a = 2, i = 0; i <= c; i++) {
		if(i >= c-i) {
			ll t = get(c, i);
			while(n >= t && t) {
				ans.pb(a);
				suf.pb(a);
				a++;
			
				n -= t;
			}
		}
		if(i != c)
			ans.pb(1);
	}
	
	reverse(all(suf));
	for(auto i : suf) ans.pb(i);
	
	
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << " ";
}
