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

void solve() {
	ll a, b;
	char x;
	cin >> a >> x >> b;
	if (x == '+') {
		cout << a + b;
	}
	else {
		cout << a - b;
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