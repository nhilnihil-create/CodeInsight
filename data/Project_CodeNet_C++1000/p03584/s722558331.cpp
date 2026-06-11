#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long LL;
const int MaxN = 1e5;
using namespace std;
int n, K;
int a[MaxN + 5], b[MaxN + 5];
int main() 
{
	while(~scanf("%d%d", &n, &K)) {
		K++;
		for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
		LL ans = 0, now = 0;
		for (int P = 30; P >= 0; P--) {
			if(K & (1 << P)) {
				now ^= (1 << P);
				LL tmp = 0;
				for (int i = 1; i <= n; i++) {
					if((a[i] & now) == 0) tmp = tmp + b[i];
				}
				ans = max(ans, tmp);
				now ^= (1 << P);
			}
			else {
				now ^= (1 << P);
			}
		}
		printf("%lld\n", ans);
	}
}