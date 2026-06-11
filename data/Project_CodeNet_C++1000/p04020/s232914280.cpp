#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n;scanf("%d",&n);n--;
	int t,q;scanf("%d",&t);
	long long ans=t/2;t%=2;
	while(n--){
		scanf("%d",&q);
		ans+=min(q,t)+(q-min(q,t))/2;
		t=(q-min(q,t))&1;
	}
	printf("%lld\n",ans);
	return 0;
}