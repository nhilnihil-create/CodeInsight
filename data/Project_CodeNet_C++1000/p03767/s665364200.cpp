#include<bits/stdc++.h>
using namespace std;
int a[300005];
signed main(){
	int n;scanf("%d",&n);
	for(register int i=1;i<=3*n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+3*n+1);
	long long ans=0;
	for(register int i=3*n-1;i>=n+1;i-=2){
		ans+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}