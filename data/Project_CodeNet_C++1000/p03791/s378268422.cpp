#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/stack:256000000")

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <cmath>
#include <cassert>
#include <ctime>
#include <memory.h>

using namespace std;

#define fo(a,b,c) for(int a=(b);a<(c);a++)
#define fd(a,b,c) for(int a=(b);a>=(c);a--)
#define fi(a) fo(i,0,(a))
#define fj(a) fo(j,0,(a))
#define fk(a) fo(k,0,(a))
#define _(a,b) memset((a),(b),sizeof(a))
#define __(a) memset((a),0,sizeof(a))
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#ifdef _DEBUG
#define dbg(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << (x) << endl;}
#else
#define dbg(...) {}
#define dbgx(x) {}
#endif

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
}

const int maxn = 100100;
const lint mod = INF + 7;

int n, x[maxn];

void read()
{
	scanf("%d", &n);
	fi(n)
		scanf("%d", &x[i]);
}

lint get(int id, int cnt)
{
	if (id >= n)
	{
		lint res = 1;
		fi(cnt)
			(res *= i + 1) %= mod;
		return res;
	}
	x[id] = min(x[id], x[id - 1] + 2);
	if (x[id] - x[id - 1] < 2)
	{
		x[id] = x[id - 1];
		return (lint)(cnt + 1) * get(id + 1, cnt) % mod;
	}
	return get(id + 1, cnt + 1);
}

bool solve()
{
	lint res = 1, mod = INF + 7, cur = 1, cnt = 1;
	x[0] = 1;
	cout << get(1, 1) << endl;
	return false;
}

int main()
{
	prepare();
	read();
	while (solve());
	return 0;
}