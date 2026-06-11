#include<bits/stdc++.h>
const int N=1e5+5;
int x[N],n,m,i,j,b[N],c[N],z[N];
long long k,ans;
void solve(){
	if(k==0)return;
	int y=k&1;k>>=1;solve();
	for(memcpy(z+1,c+1,n-1<<2),i=1;i<n;++i)c[i]=z[c[i]];
	if(y)for(memcpy(z+1,c+1,n-1<<2),i=1;i<n;++i)c[i]=z[b[i]];
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",x+i),b[i]=c[i]=i;for(i=n;i;--i)x[i]-=x[i-1];
	scanf("%d%lld",&m,&k);for(i=1;i<=m;++i)scanf("%d",&j),std::swap(b[j-1],b[j]);
	solve();printf("%lld\n",ans=x[1]);
	for(i=1;i<n;++i)printf("%lld\n",ans+=x[c[i]+1]);
	return 0;
}