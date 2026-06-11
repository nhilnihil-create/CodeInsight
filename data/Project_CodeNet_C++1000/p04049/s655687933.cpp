#include<bits/stdc++.h>
using namespace std;
int n,k;
struct edge 
{ 
	int y;
	int next; 
}e[5100];
int a[2100];
int b[2100];
int lin[2100];
int len;
int sum;
int ans=0x3f3f3f3f;
void DJ(int xx,int yy) 
{
	e[++len].y=yy;
	e[len].next=lin[xx];
	lin[xx]=len;
}
void dfs(int x,int fa,int deep) 
{
	if(deep>k)	
	++sum;
	for(int i=lin[x];i;i=e[i].next) 
	{
		int y=e[i].y;
		if(y==fa)	
		continue;
		dfs(y,x,deep+1);
	}
}
int main() 
{
	cin>>n>>k;
	for(int i=2;i<=n;i++) 
	{
		int x;
		int y;
		cin>>x>>y;
		DJ(x,y);
		DJ(y,x);
		a[i]=x;
		b[i]=y;
	}
	if(k&1) 
	{
		k>>=1;
		for(int i=2;i<=n;i++) 
		{
			sum=0;
			dfs(a[i],b[i],0);
			dfs(b[i],a[i],0);
			ans=min(ans,sum);
		}
	} 
	else 
	{
		k>>=1;
		for(int i=2;i<=n;i++) 
		{
			sum=0;
			dfs(i,0,0);
			ans=min(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}
/*
6 5
1 2
3 2
4 2
1 6
5 6
*/