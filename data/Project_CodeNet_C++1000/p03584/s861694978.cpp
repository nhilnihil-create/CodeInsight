/********************************************
 *Author*        :ZZZZone
 *Created Time*  : 二 10/ 3 19:57:21 2017
 * Ended  Time*  : 四 10/ 5 14:17:39 2017
*********************************************/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MaxN = 1e5;

int n;
LL k;
LL a[MaxN + 5], b[MaxN + 5];

int main(){
	while(~scanf("%d %lld", &n, &k)){
		k++;
		for(int i = 1; i <= n; i++) scanf("%lld %lld", &a[i], &b[i]);
		LL now = 0, ans = 0;
		for(int t = 30; t >= 0; t--){
			now = now ^(1 << t);
			if(k &(1 << t)){
				LL tmp = 0;
				for(int i = 1; i <= n; i++) 
					if((a[i] & now) == 0) tmp += b[i];
				ans = max(ans, tmp);
				now = now ^(1 << t);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
