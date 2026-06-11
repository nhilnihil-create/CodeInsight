#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005];
long long l,r,mid,ans;

bool check(long long x){
	for(int i=1;i<=n;i++){
		if(a[i]>x) b[i]=1;
		else b[i]=0;
	}
	int u=n/2+1;
	int v=u,w=u;
	while(b[v-1]!=b[v]&&v>1) v--;
	while(b[w+1]!=b[w]&&w<n) w++;
	if(v==1&&w==n){
		if(u&1) return b[u];
		else return b[u]^1;
	}
	if(u-v+1<w-u+1) return b[v];
	else return b[w];
}

int main(){
	scanf("%d",&n);
	n=2*n-1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	l=0,r=1e10,ans=1e10+7;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else{
			r=mid-1;
			ans=min(ans,mid);
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}