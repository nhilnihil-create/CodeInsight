//Khodaya aghideye man ra az dast oghde am masoon dar!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
#pragma optimize O3
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2007;
const int MAXS = (int)2007 * 2007;
const int infint = (ll)1e9;
const ll inf = (ll)1e18;
ll n, k, dp[MAXN][MAXN], fact[MAXS], facrev[MAXS];
ll pwr(ll a, ll b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	ll c = pwr(a, b / 2);
	c = (c * c) % MOD;
	if(b % 2)
		c = (c * a) % MOD;
	return c;
}
ll inv(ll p)
{
	return pwr(p, MOD - 2);
}
ll C(ll n, ll k)
{
	ll mul = fact[n];
	mul = (mul * facrev[k]) % MOD;
	mul = (mul * facrev[n - k]) % MOD;
	return mul;
}
ll f(ll open, ll i)
{
	if(open > i || open < 0)
		return 0;
	if(dp[open][i] != -1)
		return dp[open][i];
	if(open + i == 0)
		return dp[open][i] = 1;
	ll sz = i * k - open;
	ll ans = f(open + 1, i);
	ll ans2 = f(open - 1, i - 1) * i % MOD * C(sz - 1, k - 2) % MOD;
	return dp[open][i] = (ans + ans2) % MOD;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	fact[0] = 1;
	for (int i = 1; i < MAXS; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	facrev[MAXS - 1] = inv(fact[MAXS - 1]);
	for (int i = MAXS - 1; i > 0; i--)
		facrev[i - 1] = (facrev[i] * i) % MOD;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			dp[i][j] = -1;
	if(k == 1)
		return cout << 1, 0;
	cout << f(0, n);
}