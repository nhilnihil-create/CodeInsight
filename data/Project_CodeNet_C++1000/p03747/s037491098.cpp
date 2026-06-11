#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 1e5 + 5;
LL x[MAXN], w[MAXN], ans[MAXN];
int main(){
	LL n, l, t, i, j = 1;
	scanf("%lld %lld %lld", &n, &l, &t);
	for(i = 1 ; i <= n ; ++i){
		scanf("%lld %lld", &x[i], &w[i]);
		ans[i] = x[i] + (w[i] == 1 ? t : -t);
		ans[i] = (ans[i] % l + l) % l;
	}
	for(i = 1 ; i <= n ; ++i){
		LL r = x[i] + (w[i] == 1 ? t : -t);
		j +=  r / l;
		r %= l;
		if(r < 0) --j;
	}
	sort(ans + 1, ans + 1 + n);
	j = (j % n + n) % n;
	if(j == 0) j = n;
	for(i = j ; i <= n ; ++i)
		printf("%lld\n", ans[i]);
	for(i = 1 ; i < j ; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}