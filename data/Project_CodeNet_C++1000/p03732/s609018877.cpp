#include <cstdio>
#include <algorithm>
#define MAXN 105
#define ll long long
using namespace std;
bool cmp(ll x, ll y) {
	return x > y;
}
ll n, w, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
ll stan, we, va, ca, cb, cc, cd;

int main() {
	long long ans = 0;
	scanf("%lld%lld", &n, &w);
	scanf("%lld%lld", &we, &va);
	stan = we;
	a[++ca] = va;
	for(int i = 2; i <= n; i++) {
		scanf("%lld%lld", &we, &va);
		if(we-stan == 1) b[++cb] = va;
		else if(we-stan == 2) c[++cc] = va; 
		else if(we-stan == 3) d[++cd] = va;
		else if(we == stan) a[++ca] = va;
	}
	sort(a+1, a+1+ca, cmp);
	sort(b+1, b+1+cb, cmp);
	sort(c+1, c+1+cc, cmp);
	sort(d+1, d+1+cd, cmp);
	
	for(int i = 1; i <= ca; i++) a[i] += a[i-1];
	for(int i = 1; i <= cb; i++) b[i] += b[i-1];
	for(int i = 1; i <= cc; i++) c[i] += c[i-1];
	for(int i = 1; i <= cd; i++) d[i] += d[i-1];
	
	for(int i = 0;  i <= ca; i++) 
		for(int j = 0; j <= cb; j++)
			for(int m = 0; m <= cc; m++)
				for(int m1 = 0; m1 <= cd; m1++) 
					if(i*stan + (stan+1)*j + (stan+2)*m + (stan+3)*m1 <= w)
						ans = max(ans, a[i]+b[j]+c[m]+d[m1]);
	printf("%lld\n", ans);
	
	return 0;
}