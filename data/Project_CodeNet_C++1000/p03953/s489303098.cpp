#include <cstdio>
#include <algorithm>
#include <vector>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long LL;
const int N = 100010;

LL x[N], x0[N], r[N][62], fx[N], cx0[N];

int main()
{
	int n, m;
	LL k;
	scanf("%d", &n);
	Rep(i, n) scanf("%lld", &x[i]);
	Rep(i, n - 1) x0[i] = i, cx0[i] = x[i + 1] - x[i];
	scanf("%d%lld", &m, &k);
	Rep(i, m) {
		int a;
		scanf("%d", &a);
		//printf("%d<-->%d\n", a, a - 1);
		swap(x0[a], x0[a - 1]);
	}
	Rep(i, n - 1) r[i][0] = x0[i];
	Rep(j, 60) Rep(i, n - 1) r[i][j] = r[r[i][j - 1]][j - 1];
	Rep(i, n - 1) fx[i] = i;
	for (int i = 60; i >= 0; i --) if (k >= (1ll << i)) {
		k -= (1ll << i);
		Rep(j, n - 1) fx[j] = r[fx[j]][i];
	}
	LL sum = x[1];
	printf("%lld\n", sum);
	Rep(i, n - 1) {
		sum += cx0[fx[i]];
		printf("%lld\n", sum);
	}
	
	return 0;
}