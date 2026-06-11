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

int dp[50][500][500];

int main()
{
	int n, ma, mb; cin >> n >> ma >> mb;
	int INF = 1e4;
	vector<int> a(n), b(n), c(n);
	rep(i, n)cin >> a[i] >> b[i] >> c[i];
	rep(i, 50)rep(j, 450)rep(k, 450)dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	rep(i, n)rep(j, 405)rep(k, 405)
	{
		chmin(dp[i + 1][j][k], dp[i][j][k]);
		chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
	}
	int res = INF;
	rep(i, n + 1)rep(j, 405)rep(k, 405)
	{
		if (i*j*k == 0)continue;
		if (j*mb == k * ma)chmin(res, dp[i][j][k]);
	}
	if (res == INF)cout << -1 << endl;
	else cout << res << endl;
}