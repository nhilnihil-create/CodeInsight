#include <bits/stdc++.h>
#define N 200010
#define int long long 
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,m,k,d[N],s[N],fin[N];
int now[N],cnt,rk[N],vis[N];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		d[i]=read();
	for(int i=2;i<=n;i++) s[i-1]=d[i]-d[i-1];
	m=read(); k=read();
	for(int i=1;i<n;i++) rk[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=read();
		swap(rk[x],rk[x-1]);
	} 
	//zhihuan
	for(int i=1;i<n;i++) if(!vis[i])
	{
		int x=rk[i]; 
		now[0]=i; 
		vis[i]=1;
		cnt=1;
		while(!vis[x])
		{
			vis[x]=1;
			now[cnt++]=x;
			x=rk[x];
		}
		for(int i=0;i<cnt;i++)
			fin[now[i]]=now[(i+k)%cnt];
	}
	
	printf("%lld\n",d[1]);
	for(int i=1;i<n;i++)
	{
		d[1]+=s[fin[i]];
		printf("%lld\n",d[1]);
	}
	return 0;
}