#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long sum[200005];
int main(){
	int i;
	int n;
	long long ans=0x7fffffffffffffff;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%lld", &sum[i]);
		sum[i]+=sum[i-1];
	}
	for(i=1; i<n; i++){
		ans=min(ans, abs(sum[n]-2*sum[i]));
	}
	printf("%d", ans);
	return 0;
}