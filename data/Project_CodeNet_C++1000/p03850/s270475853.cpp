#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)
#define RepG(i, x) for (int i = head[x]; i; i = edge[i].next)
#define v edge[i].to
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long LL;
const int N = 100010;

LL f[N][4], c[N], a[N];
char op[2];

int main()
{
	int n;
	scanf("%d", &n);
	Rep(i, n) {
		if (i != 1) scanf("%s", op);
		if (i == 1 || op[0] == '+') c[i] = 1;
		else c[i] = -1;
		scanf("%lld", &a[i]);
	}
	Rep0(i, n) Rep0(j, 2) f[i][j] = -1e18;
	f[0][0] = 0;
	Rep0(i, n) Rep0(j, 2){
		LL tt = j == 1 ? -1 : 1;
		if (j) {
			f[i + 1][j - 1] = max(f[i + 1][j - 1], f[i][j] - tt * c[i + 1] * a[i + 1]);
			if (c[i + 1] == -1) f[i + 1][j] = max(f[i + 1][j], f[i][j] + tt * a[i + 1]);
		}
		if (c[i + 1] == -1)
			f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + tt * c[i + 1] * a[i + 1]);
		f[i + 1][j] = max(f[i + 1][j], f[i][j] + tt * c[i + 1] * a[i + 1]);
	}
	printf("%lld\n", max(f[n][0], max(f[n][1], f[n][2])));
	
	return 0;
}
