#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <set>
#include <deque>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define ev g[i].y
#define eps 1e-10
#define pb push_back
#define pf push_front
using namespace std;
typedef long long ll;
typedef double db;
const int N = 100005, mod = 1000000007;
ll n;
int m;
deque<int> a, b;
void work(ll x) {
	if (x == 1) return ;
	work(x / 2);
	++ m;
	a.pb(m), b.pb(m);
	if (x & 1) {
		++ m;
		a.pb(m), b.pf(m);
	}
}
int main()
{
	scanf ("%lld", &n);
	work(n + 1);
	printf("%d\n", a.size() + b.size());
	for (auto it = a.begin(); it != a.end(); it ++) printf("%d\n", *it);
	for (auto it = b.begin(); it != b.end(); it ++) printf("%d\n", *it);

	return 0;
}