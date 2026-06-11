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
#define pb emplace_back
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

vi xx = { 1, 0, -1, 0 };
vi yy = { 0, 1, 0, -1 };
string dir = "LRUD";

const int N = 3e5 + 50, oo = 2e18 + 500;
const int mod = 998244353;
//const int mod = 1e9 + 7;
//const int mod = 1e9 + 9;
const double eps = 1e-9, PI = 2 * acos(0.0);
int n, m, k;
long long cnt = 0;
int lg = 18;
vvi g;
//vi rg[N];
vi visit(N, 0);

vi t;
void add(int ind, int v)
{
	ind++;
	for (int i = ind; i < SZ(t); i += i&-i)
	{
		t[i] += v;
	}
}

int get(int ind)
{
	ind++;
	int res = 0;
	for (int i = ind; i; i -= i&-i)
	{
		res += t[i];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("rblock.in", "r", stdin);
	//freopen("rblock.out", "w", stdout);

	cin >> m >> n;

	vpii seg;
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		seg.pb(r - l + 1, l);
	}

	sort(all(seg));
	vi ans(n);

	int j = 0;
	t.assign(n + 10, 0);
	for (int i = 1; i <= n; i++)
	{
		while (j < m && seg[j].first < i)
		{
			int l = seg[j].second;
			int r = seg[j].first + l - 1;
			add(l, 1);
			add(r + 1, -1);
			j++;
		}

		ans[i - 1] = m - j;
		for (int z = i; z <= n; z += i)
		{
			ans[i - 1] += get(z);
		}
	}

	for (auto x : ans)
	{
		cout << x << endl;
	}
}