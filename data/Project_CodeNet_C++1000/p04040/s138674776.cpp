#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const ll mod = 1e9 + 7;
const int maxn = 3e5 + 5;

ll f[maxn];

ll mod_exp(ll a, ll b){
	if(b == 0)
		return 1ll;
	if(b % 2 == 0){
		ll t = mod_exp(a, b / 2) % mod;
		return t * t % mod;
	}
	return a * mod_exp(a, b - 1) % mod;
}

ll inv(ll x){
	return mod_exp(x, mod - 2) % mod;
}

ll n_k(int n, int k){
	if(k > n)
		return 0ll;

	ll num = f[n], den = f[k] * f[n - k] % mod;
	return num * inv(den) % mod;
}

ll ways(int n, int m){
	return n_k(n + m, n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("capastaty_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	f[0] = 1ll;
	for(int i = 1; i < maxn; i++)
		f[i] = (f[i - 1] * 1ll * i) % mod;

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	ll total = ways(n - 1, m - 1);
	int i = n - a + 1, j = b;
	while(i <= n && j >= 1){

		ll w1 = ways(i - 1, j - 1);
		ll w2 = ways(n - i, m - j);
		total = (total + mod - w1 * w2 % mod) % mod;
		i++;
		j--;
	}

	cout << total << endl;

	return 0;
}
