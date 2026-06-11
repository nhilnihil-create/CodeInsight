#include <stdio.h>
#include <string.h>
#define N 200002
typedef unsigned long long LL;

int a[N], lp[N], rp[N];
LL ans;

int main()
{	
	int n, i, tp, t;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", a + i);
	a[0] = a[n + 1] = 0;
	for(lp[1] = 0, i = 2; i <= n; i++){
		tp = i - 1, t = a[i];
		while(a[tp] > t) tp = lp[tp];
		lp[i] = tp;
	}
	
	ans = (LL)a[n] * (LL)(n - lp[n]); 
	for(rp[n] = n + 1, i = n - 1; i >= 1; i--){
		tp = i + 1, t = a[i];
		while(a[tp] > t) tp = rp[tp];
		rp[i] = tp;
		ans += (LL)t * (LL)(tp - i) * (LL)(i - lp[i]);
	}
	printf("%llu\n", ans);	
	
	return 0;
}