/************************************************
*Author        :  lrj124
*Created Time  :  2018.10.24.19:28
*Mail          :  1584634848@qq.com
*Problem       :  d
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n,k,a[maxn],b[maxn];
long long ans;
int main() {
	//freopen("d.in","r",stdin);
	//freopen("d.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		if ((a[i]|k) == k) ans += b[i];
	}
	for (int i = 1;i <= 30;i++)
		if (k&(1<<i)) {
			int K = k^(1<<i)|(1<<i)-1;
			long long cnt = 0;
			for (int j = 1;j <= n;j++)
				if ((a[j]|K) == K) cnt += b[j];
			ans = max(ans,cnt);
		}
	printf("%lld",ans);
	return 0;
}