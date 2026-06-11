#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e5+10;

int n,m,tot,st,d[N],id[N],nt[N];
ll K;int ans[N],q[N],cnt,vs[N],p[N];

int main(){
	int i,j,x,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i) scanf("%d",&p[i]);
	for(i=2;i<=n;++i) d[i]=p[i]-p[i-1],id[i]=i;
	scanf("%d%lld",&m,&K);
	for(i=1;i<=m;++i){scanf("%d",&x);swap(id[x],id[x+1]);}
	for(i=2;i<=n;++i) nt[id[i]]=i;
	for(i=2;i<=n;++i) if(!vs[i]){
		for(cnt=0,j=i;!vs[j];j=nt[j]){
			q[++cnt]=j;vs[j]=1;
		}
		x=K%cnt;k=x%cnt+1;
		for(j=1;j<=cnt;++j){
			ans[q[k]]=d[q[j]];
			k= k==cnt?1:(k+1);
		}
	}
	ll pos=(ll)p[1];
	for(i=1;i<=n;++i){
		pos+=ans[i];
		printf("%.10lf\n",(db)pos);
	}
	return 0;
}