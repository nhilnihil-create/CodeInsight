#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200105],sum=0;
int d[200105][35],n;
inline ll read()
{
	char c=getchar();ll a=1;ll ans=0;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')a=-1;
	for(;c>='0'&&c<='9';c=getchar())ans=ans*10+ll(c)-48;
	return a*ans;
}
int aaaa(int s,int v)
{
	int k=log((v-s+1)*1.0)/log(2.0);
	if(a[d[s][k]]<a[d[v-(1<<k)+1][k]])
	{
		return d[s][k];
	}
	else 
	{
		return d[v-(1<<k)+1][k];
	}
}
void dfs(int l,int r)
{
	if(l==r)
	{
		sum+=a[l];
		return;
	}
	int minn=aaaa(l,r);
	sum=sum+(ll)(minn-l+1)*(r-minn+1)*a[minn];
	if(l<=minn-1)
	{
		dfs(l,minn-1);
	}
	if(r>=minn+1)
	{
		dfs(minn+1,r);
	}
}
int main()
{
	n=read();
	for(int i=0;i<n;i++)
	{
		a[i]=read();
	}
	for(int i=0;i<n;i++)
	{
		d[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=0;i+(1<<j)-1<n;i++)
		{
			if(a[d[i][j-1]]<a[d[i+(1<<(j-1))][j-1]])
			{
				d[i][j]=d[i][j-1];
			}
			else 
			{
				d[i][j]=d[i+(1<<(j-1))][j-1];
			}
		}
	}
	dfs(0,n-1);
	printf("%lld\n",sum);
	return 0;
}