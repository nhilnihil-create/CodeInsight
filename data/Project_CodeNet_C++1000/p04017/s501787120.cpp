#define _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "algorithm"
#include "iomanip"
#include "stack"
#include "queue"
#include "string"
#include "vector"
#include "map"
#include "set"
#include "list"
#include "deque"
#include "complex"
#include "bitset"
#include "cmath"
#include "unordered_set"
#include "unordered_map"
#include "iterator"
#include <ctime>
#include <cassert>
#include "numeric"
#include <cstdio>
#include "random"
#include "chrono"
#include "cstring"

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target_ans("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

//#define f(i,n) for(int i=0; i<n;i++)
//#define rf(i, n) for(int i=n-1;i>=0;i--)
//#define forn(i, j, n) for(int i=j; i<n; i++)
//#define ff(i, j, n) f(i, n)f(j, n)
#define pb push_back
#define maxi(a,b) a = max(a, b);
#define mini(a,b) a = min(a, b);
#define endl '\n'

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sqr(x) ((x) * (x))
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;
//typedef long long ll;
typedef long double ld;

#define int long long
//#define int unsigned int
#define double ld
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vpii;
typedef vector<char> vc;
typedef vector<vi> vvi;

template<class T>
void show(const vector<T> &a)
{
	for (T x : a)
		cout << x << " ";
	cout << endl;
}

vi xx = { 1, 0, -1, 0 };
vi yy = { 0, 1, 0, -1 };
string dir = "LRUD";

const int N = 2e5 + 50, oo = 5e18 + 500;
const int mod = 998244353;
//const int mod = 1e9 + 7;
//const int mod = 1e9 + 9;
const double eps = 1e-6, PI = 2 * acos(0.0);
int n, m, k;
int cnt = 0;
int lg = 18;
vi g[N];
vi rg[N];
vi visit(N, 0);



signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;

	vi x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	cin >> m >> k;

	vvi dp(n, vi(lg, oo));
	for (int i = 0; i < n - 1; i++)
	{
		dp[i][0] = upper_bound(all(x), x[i] + m) - x.begin() - 1;
	}

	for (int j = 1; j < lg; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (dp[i][j - 1] == oo)
			{
				dp[i][j] = oo;
				continue;
			}
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

	while (k--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;

		if (l > r)
			swap(l, r);

		cnt = 0;
		for (int j = lg - 1; j >= 0; j--)
		{
			if (dp[l][j] <= r)
			{
				l = dp[l][j];
				cnt += (1 << j);
			}
		}

		if (l < r)
			cnt++;

		cout << cnt << endl;
	}
}

