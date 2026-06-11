#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],d[100010],nxt[100010],id[100010];
long long k,ans[100010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),d[i]=i,id[i]=i;
	scanf("%d %lld",&m,&k);
	for(int i=1,w;i<=m;i++) scanf("%d",&w),swap(id[w],id[w+1]);
	for(;k;k>>=1){
		if(k&1){
			for(int i=1;i<=n;i++) nxt[i]=d[id[i]];
			for(int i=1;i<=n;i++) d[i]=nxt[i];
		}
		for(int i=1;i<=n;i++) nxt[i]=id[id[i]];
		for(int i=1;i<=n;i++) id[i]=nxt[i];
	}
	for(int i=1;i<=n;i++) ans[i]=a[d[i]]-a[d[i]-1];
	for(int i=1;i<=n;i++) printf("%lld.0\n",ans[i]+=ans[i-1]);
}