#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using base = complex<double>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define M2 998244353
#define ll long long
#define pll pair<long, long>
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define ff first
#define ss second
#define pb push_back
#define db pop_back
#define mp make_pair
#define mt make_tuple
#define g(a, b) get<a>(b)
#define INF (ll)1e18 + 100
#define vl vector<ll>
#define vi vector<int>
#define vll vector<pair<ll, ll>>
#define vii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))
#define INT_SIZE 32

ll powM(ll x, ll y, ll m)
{
	ll ans = 1, r = 1;
	x %= m;
	while (r > 0 && r <= y)
	{
		if (r & y)
		{
			ans *= x;
			ans %= m;
		}
		r <<= 1;
		x *= x;
		x %= m;
	}
	return ans;
}


void solve() {
	ll n;
	cin >> n;
	map<ll, ll>m;
	REP(i, 0, n) {
		ll x;
		cin >> x;
		m[x]++;
	}
	ll ans = 1;
	if (n % 2) {
		if (m[0] != 1) {
			cout << 0; return;
		}
		for (auto y : m) {
			if (y.ff != 0) {
				if (y.ff % 2) {cout << 0; return;}
				if (y.ss != 2) {
					cout << 0; return;
				}
				if (y.ff > n - 1) {
					cout << 0; return;
				}
			}
		}
		cout << powM(2, m.size() - 1, M);
	}
	else {
		for (auto y : m) {
			if (y.ff % 2 == 0) {cout << 0; return;}
			if (y.ss != 2) {
				cout << 0; return;
			}
			if (y.ff > n - 1) {
				cout << 0; return;
			}
		}
		cout << powM(2, m.size(), M);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll ntc;
	// cin >> ntc;
	ntc = 1;
	REP(tc, 1, ntc + 1)
	{
		// cout << "Case #" << tc << ": ";
		solve();
	}
}