#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;

inline int f(int x) {
	return x / 2;
}

int n, m;
vector <int> v;

vector <int> res;

int main()
{
	boost;
	cin >> n >> m;
	int fn = 0, on = 0, a;
	
	FOR(i, 1, m)
	{
		cin >> a;
		if (a % 2 == 1)
		{
			if (fn && on) OUT("Impossible");
			if (fn) on = a;
			else fn = a;
		}
		else v.pb(a);
	}
	
	if (!fn)
	{
		for (auto u : v) cout << u << ' ';
		cout << "\n";
		res.pb(1);
		for (auto u : v) res.pb(u);
		res[res.size() - 1]--;
		cout << (int)res.size() << "\n";
		for (auto u : res) cout << u << ' ';
	}
	else if (!on)
	{
		cout << fn << ' ';
		for (auto u : v) cout << u << ' ';
		cout << "\n";
		FOR(i, 1, f(fn) + 1) res.pb(2);
		for (auto u : v) res.pb(u);
		res[res.size() - 1]--;
		cout << (int)res.size() << "\n";
		for (auto u : res) cout << u << ' ';
	}
	else
	{
		cout << fn << ' ';
		for (auto u : v) cout << u << ' ';
		cout << on << "\n";
		FOR(i, 1, f(fn) + 1) res.pb(2);
		for (auto u : v) res.pb(u);
		FOR(i, 1, f(on)) res.pb(2);
		cout << (int)res.size() << "\n";
		for (auto u : res) cout << u << ' ';
	}
}
