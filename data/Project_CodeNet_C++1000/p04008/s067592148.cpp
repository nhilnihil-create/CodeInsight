#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
#define N 1000002
struct edge{int to,nxxt;}e[N];
int n,k,a[N],ans,head[N],cnt=1;
int len[N];
bool vis[N];
inline void ins(int u,int v){e[cnt].to=v;e[cnt].nxxt=head[u];head[u]=cnt++;}
void df5(int te,int la)
{len[te]=1;
	for(int i=head[te];i;i=e[i].nxxt)
	{
		int j=e[i].to;if(j==la)continue;
		df5(j,te);if(vis[j])continue;
		if(len[j]+1>len[te])len[te]=len[j]+1;
	}
	if(te!=1&&la!=1&&len[te]>=k)vis[te]=1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[1]^1)ans++;
	for(int i=2;i<=n;i++)ins(a[i],i);
	df5(1,1);for(int i=2;i<=n;i++)ans+=vis[i];
	printf("%d\n",ans);
}
