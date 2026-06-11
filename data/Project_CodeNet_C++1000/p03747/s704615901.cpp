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
#include <map>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define ev g[i].y
using namespace std;
typedef long long ll;
typedef double db;
const int N = 100010;
int n, L, t, p, k;
struct arr { int x, id, t; } a[N];
bool cmp(arr a, arr b) { return a.x == b.x ? a.t > b.t : a.x < b.x; }
int main()
{
	scanf ("%d%d%d", &n, &L, &t);
	Rep(i, 1, n) {
		scanf ("%d%d", &a[i].x, &a[i].t);
		a[i].id = i;
		if (a[i].t == 1) k = i;
	}
	if (k) {
		p = 0;
		int y, z;
		Rep(i, 1, n) if (a[i].t == 2) {
			y = (a[i].x - a[k].x + L) % L;
			if (2 * t >= y) z = (2 * t - y) / L + 1;
			else z = 0;
			(p += z) %= n;
		}
		p = (k + p - 1) % n + 1;
		// cout << k<<" "<<p<<endl;
	}
	Rep(i, 1, n) {
		if (a[i].t == 1) a[i].x = (a[i].x + t) % L;
		else a[i].x = (a[i].x + L - t % L) % L;
	}
	if (!k) {
		Rep(i, 1, n) printf("%d\n", a[i].x);
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	int x;
	Rep(i, 1, n) if (a[i].id == k) {
		x = (n - p + i) % n + 1;
		break ;
	}
	for(int i = x;;) {
		printf("%d\n", a[i].x);
		i = i % n + 1;
		if (i == x) break ;
	}

	return 0;
}