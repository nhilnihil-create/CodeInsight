#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 60;

int n, l, r;
ll S, a[N], c[N][N];

int main() {
	c[0][0] = 1;
	for(int i = 1; i <= 50; ++i) {
		c[0][i] = c[i][i] = 1;
		for(int j = 1; j < i; ++j) {
			c[j][i] = c[j][i - 1] + c[j - 1][i - 1];
		}
	}
	scanf("%d%d%d", &n, &l, &r);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= l; ++i) S += a[i];
	printf("%.15Lf\n", (long double)S / l);
	int cnt = 0, tot = 0;
	for(int i = l; i; --i) 
		if(a[i] == a[l]) ++cnt;
	for(int i = 1; i <= n; ++i) 
		if(a[i] == a[l]) ++tot;
	if(a[1] == a[l]) {
		ll ans = 0;
		for(int i = l; i <= r; ++i) ans += c[i][tot];
		printf("%lld\n", ans);
	} else printf("%lld\n", c[cnt][tot]);
	return 0;
} 