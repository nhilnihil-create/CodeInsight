#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define dwn(i, r, l) for (int i = r; i >= l; i --)
#define repG(u, i) for (int i = hd[u]; i; i = e[i].nxt)
#define ev e[i].v
#define ec e[i].c
#define sqr(x) (x)*(x)
#define rlxX(x, y) x = max(x, y)
#define rlxN(x, y) x = min(x, y)
#define clr(a, b) memset(a, b, sizeof(a))
#define gc getchar()

typedef long long LL;
typedef double db;
const int N = 5e3 + 5, mod = 1e9 + 7;

int rd() {
	char ch = gc; int ret = 0;
	while (ch < '0' || ch > '9') ch = gc;
	while (ch >= '0' && ch <= '9') ret = ret*10 + ch-'0', ch = gc;
	return ret;
}

int n, m, f[N][N];
char str[N];

int Pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll*res*a%mod;
		a = 1ll*a*a%mod;
		b >>= 1;
	}
	return res;
}

int main(){
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	n = rd();
	scanf("%s", str);
	m = strlen(str);
	f[0][0] = 1;
	rep(i, 1, n)
		rep(j, 0, i) {
			if (j) f[i][j] = (f[i][j] + (f[i-1][j-1]<<1)%mod)%mod;
			else f[i][j] = (f[i][j] + f[i-1][j])%mod;
			f[i][j] = (f[i][j] + f[i-1][j+1])%mod;
		}
	//printf("%d\n", Pow(2, m));
	printf("%d\n", 1ll*f[n][m]*Pow(Pow(2, m), mod-2)%mod);
	
	return 0;
}
/*

*/

