//Heaplax
#include<bits/stdc++.h>
#define N 100005
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
    while(ch=getchar(),ch<33);
    if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
    while(ch=getchar(),ch>33)x=x*10+ch-48;
    if(fs)x=-x;
}
using namespace std;
int n,k,a[N],ans,in[N],dis[N],top,st[N];
int main()
{
	re(n),re(k);
	for(int i=1;i<=n;++i)
		re(a[i]);
	ans+=a[1]!=1;
	a[1]=1;
	for(int i=2;i<=n;++i)
		++in[a[i]];
	for(int i=2;i<=n;++i)
		if(!in[i])
			st[++top]=i;
	for(int i=1;i<=top;++i)
	{
		int u=st[i];
		if(dis[u]+1==k && a[u]!=1)++ans;
		else dis[a[u]]=max(dis[a[u]],dis[u]+1);
		if(a[u]!=1)
		{
			--in[a[u]];
			if(!in[a[u]])
				st[++top]=a[u];
		}
	}
	printf("%d\n",ans);
}