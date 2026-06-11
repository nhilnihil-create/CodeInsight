#include<cstdio>
#include<algorithm>
#include<cstring>
#define MN 100005
using namespace std;
int n,m,c[MN],tmp[MN];
long long a[MN],v[MN],k,ans[MN],sum;
bool vis[MN];
int main(){
	scanf("%d",&n);int x;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		v[i]=a[i]-a[i-1],c[i]=i;
	}scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++)scanf("%d",&x),swap(c[x],c[x+1]);
	for(int i=1,j,tt=0;i<=n;i++,tt=0)if(!vis[i]){
		for(j=i;!vis[j];j=c[j])vis[j]=1,tmp[++tt]=j;
		for(j=1;j<=tt;j++)ans[tmp[j]]=v[tmp[(j+k-1)%tt+1]];
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1],printf("%lld.0\n",ans[i]);
}

