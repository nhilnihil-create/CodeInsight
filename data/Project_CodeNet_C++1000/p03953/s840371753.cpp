#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,k,t,m,a[200001],b[200001],c[200001],ans[200001];
double d[200001];
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)b[i]=ans[i]=i;
	scanf("%lld%lld",&m,&k);
	for(i=1;i<=m;i++){
		scanf("%lld",&t);
		swap(b[t],b[t+1]);
	}
	while(k){
		//prllf("%d\n",k);
		if(k&1){
			for(i=1;i<=n;i++)c[i]=ans[b[i]];
			for(i=1;i<=n;i++)ans[i]=c[i];
		}
		for(i=1;i<=n;i++)c[i]=b[b[i]];
		for(i=1;i<=n;i++)b[i]=c[i];
		k/=2;
	}
	for(i=1;i<=n;i++)d[i]=a[ans[i]]-a[ans[i]-1];
	for(i=1;i<=n;i++)printf("%.1lf\n",d[i]+=d[i-1]);
}