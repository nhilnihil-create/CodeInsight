#include <cstdio>
#include <algorithm>

typedef long long int64;

const int MAXN = 100000 + 10;

int n, m;
int a[MAXN], b[MAXN];

int main() {
	int i, j, k, m0;
	int64 tot, ans = 0;
	
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) 
		scanf("%d %d", &a[i], &b[i]);
	
	for(i=1; i<=n; i++)
		if((a[i] & m) == a[i])
			ans += b[i];
		
	for(k=31; ~k; k--) {
		if(m >> k & 1) {
			m0 = m >> (k + 1) << (k + 1) | ((1 << k) - 1);
			tot = 0;
			for(i = 1; i <= n; i++) 
				if((a[i] & m0) == a[i]) 
					tot += b[i];
			ans = std::max(ans, tot);
		}
	}
	printf("%lld\n", ans);
}