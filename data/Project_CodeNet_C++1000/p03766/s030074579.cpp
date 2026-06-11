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
#define eps 1e-10
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1000005, mod = 1000000007;
int n;
ll f[N], k;
int main()
{
	scanf ("%d", &n);
	f[0] = 1, f[1] = n;
	Rep(i, 2, n) {
		if (i >= 3) k += f[i - 3];
		f[i] = (f[i - 1] + (ll)(n - 1) * (n - 1) + (n - i + 1) + k) % mod;
	}
	printf("%lld\n", f[n]);

	return 0;
}