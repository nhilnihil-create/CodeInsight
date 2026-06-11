#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, int> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-4;
const LL INF = 1e7 - 1;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const int MAXN = 100001;
const int MAXK = 101;

LL gcd(LL x, LL y)
{
	if (!y)
		return x;
	return gcd(y, x%y);
}

LL n;
VLL a;

bool solve()
{
	LL s = 0;
	FOR(i, 0, n)
		s += a[i];

	if ((s - n) & 1)
		return 1;

	FOR(i, 0, n)
		if (a[i] == 1)
			return 0;

	int cnt = 0;
	FOR(i, 0, n)
		cnt += (a[i] & 1);

	if (cnt > 1)
		return 0;

	int g = 0;
	FOR(i, 0, n)
	{
		if (a[i] & 1)
			g = gcd(g, a[i] - 1);
		else
			g = gcd(g, a[i]);
	}

	FOR(i, 0, n)
		if (a[i] & 1)
			if (a[i] % g > 1)
				return 0;

	LL sum = 0;
	FOR(i, 0, n)
		sum += a[i] / g;

	if (sum & 1)
	{
		FOR(i, 0, n)
			a[i] /= g;

		return !solve();
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> n;
	a.resize(n);
	FOR(i, 0, n)
		cin >> a[i];

	if (solve())
		cout << "First";
	else
		cout << "Second";

	cin >> n;
	return 0;
}