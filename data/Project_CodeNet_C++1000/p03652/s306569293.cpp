//Heaplax
#include<bits/stdc++.h>
#define N 305
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
bool del[N];
int cnt[N],now[N];
int n,m,a[N][N];
bool check(int x)
{
	memset(del,0,sizeof del);
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;++i)
	{
		now[i]=1;
		++cnt[a[i][1]];
	}
	int last=m;
	while(1)
	{
		bool ok=1;
		for(int i=1;i<=m;++i)
			if(cnt[i]>x)
			{
				cnt[i]=0;
				del[i]=1;
				--last;
				if(!last)return 0;
				for(int j=1;j<=n;++j)
					if(a[j][now[j]]==i)
					{
						while(del[a[j][now[j]]])++now[j];
						++cnt[a[j][now[j]]];
					}
				ok=0;
				break;
			}
		if(ok)return 1;
	}
	return 0;
}
int main()
{
	re(n),re(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			re(a[i][j]);
	int l=1,r=n;
	while(l < r)
	{
		int m=l+r>>1;
		if(check(m))r=m;
		else l=m+1;
	}
	printf("%d\n",l);
}
