//BadWaper gg
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define N 100010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int n,m;
int vis[N],num[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	vis[1]=1;
	for(register int i=1;i<=n;i++)num[i]=1;
	for(register int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if(vis[x])
		{
			vis[y]=1;
			if(num[x]==1)vis[x]=0;
		}
		num[x]--;num[y]++;
	}
	int siz=0;
	for(register int i=1;i<=n;i++)if(vis[i]){siz++;}printf("%d\n",siz);
	return 0;
}
