#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL N,A,B;
LL h[100010];
int main () {
	scanf("%lld%lld%lld",&N,&A,&B);

	for(int i = 1;i <= N;++i)
		scanf("%lld",&h[i]);
	LL l = 1,r = 1000000000;
	LL mid;

	while(l <= r) {
		mid = (l + r) >> 1;
		LL ans = 0;
        for(int i = 1;i <= N;++i) {
            if(h[i] - mid * B > 0)
				ans += (h[i] - mid * B) / (A - B) + ((h[i] - mid * B) % (A - B) != 0);
        }
        if(ans > mid)
            l = mid + 1;
        else r = mid - 1;
	}
	printf("%lld\n",r + 1);
}
