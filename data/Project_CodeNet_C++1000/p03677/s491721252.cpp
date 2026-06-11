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
const int N = 200010;

int a[N];
LL p[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	Rep(i, n) scanf("%d", &a[i]);
	a[0] = 1;
	LL sum = 0;
	for (int i = 2; i <= n; i ++) {
		int l = a[i - 1], r = a[i];
		if (r < l) r += m;
		sum += r - l;
		if (r - l > 1) {
			p[l + 2] ++;
			p[r + 1] -= r - l;
			p[r + 2] += r - l - 1;
		}
	}
	Rep(t, 2) Rep(i, m * 2) p[i] += p[i - 1];
	LL ans = 1e18;
	Rep(i, m) ans = min(ans, sum - p[i] - p[i + m]);
	
	printf("%lld\n", ans);
	
	return 0;
}
