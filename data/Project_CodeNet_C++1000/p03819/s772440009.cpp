#include<bits/stdc++.h>
using namespace std;

void read(int &x)
{
	char c=getchar(); x=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
}

const int maxn=3e5+10;

int n,m,Ans[maxn],vis[maxn];

int main()
{
#ifdef h10
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int i,j,l,r,x;
	read(n); read(m);
	for (i=1;i<=n;i++)
	{
		read(l); read(r);
		if (!l) {Ans[1]++; continue;}
		int last=m+1,len=r-l+1,_r=(int)sqrt(r);
		Ans[1]++; Ans[len+1]--;
		for (x=1;x<=_r;x++)
		{
			int u=(l+x-1)/x,v=r/x;
			u=max(u,len+1);
			if (v<=len) break;
			if (u<=v)
			{
				if (v<last) Ans[u]++,Ans[v+1]--;
				else Ans[u]++,Ans[last]--;
				last=u;
				for (j=u;j<=v&&j<=_r&&vis[j]!=i;j++) vis[j]=i;
			}
		}
		for (x=len+1;x<=_r;x++)
		{
			int u=(l+x-1)/x,v=r/x;
			if (u<=v&&vis[x]!=i)
				vis[x]=i,Ans[x]++,Ans[x+1]--;
		}
	}
	for (i=1;i<=m;i++)
		Ans[i]+=Ans[i-1],printf("%d\n",Ans[i]);
}
