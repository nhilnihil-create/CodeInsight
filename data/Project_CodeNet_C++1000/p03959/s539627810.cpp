#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <bitset>
#include <fstream>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

#pragma region UnionFind
struct UnionFind
{
	vector<int> par;

	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }

	int root(int x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y)
	{
		return root(x) == root(y);
	}

	bool merge(int x, int y)
	{
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x)
	{
		return -par[root(x)];
	}
};
#pragma endregion
#pragma region GCD
int gcd(int a, int b)
{
	if (a%b == 0)return b;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region chmin
template<class T> inline bool chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma region chmax
template<class T> inline bool chmax(T& a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion


int main()
{
	int n; cin >> n;
	vector<ll> t(n), a(n);
	rep(i, n)cin >> t[i];
	rep(i, n)cin >> a[i];
	vector<ll> h(n);
	h[0] = t[0];
	rep(i, n - 1)if (t[i + 1] > t[i])
	{
		if (t[i + 1] <= a[i + 1])h[i + 1] = t[i + 1];
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	if (h.back() != 0 && h.back() != a.back())
	{
		cout << 0 << endl;
		return 0;
	}
	h.back() = a.back();
	rrep(i, n - 1)if (a[i] > a[i + 1])
	{
		if (h[i] == 0)
		{
			if (a[i] <= t[i])h[i] = a[i];
			else
			{
				cout << 0 << endl;
				return 0;
			}
		}
		else if (h[i] != a[i])
		{
			cout << 0 << endl;
			return 0;
		}
	}
	ll MOD = 1e9 + 7;
	ll res = 1;
	rep(i, n)
	{
		if (h[i] != 0)continue;
		res *= min(t[i], a[i]);
		res %= MOD;
	}
	cout << res << endl;
}
