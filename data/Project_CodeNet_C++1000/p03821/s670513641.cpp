#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
signed main(){
	int n;scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	long long ans=0;
	for(register int i=n;i>=1;i--){
		ans+=(b[i]-(a[i]+ans%b[i]+b[i]-1)%b[i]-1);
	}
	printf("%lld\n",ans);
	return 0;
}