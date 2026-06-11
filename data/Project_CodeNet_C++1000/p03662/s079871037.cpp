#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 654321
using namespace std;
int n,rt,size[N],fa[N],cnt=0,sum1,sum2;
int TOT,EN[N],LA[N],NE[N];
void ADD(int x,int y)
{
	TOT++;
	EN[TOT]=y;
	NE[TOT]=LA[x];
	LA[x]=TOT;
}
void DFS(int u,int f)
{
	int i,v;
	fa[u]=f;
	size[u]=1;
	for(i=LA[u];i;i=NE[i])
	{
		v=EN[i];
		if(v!=f)
		{
			DFS(v,u);
			size[u]+=size[v];
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		ADD(x,y);ADD(y,x);
	}
	DFS(1,0);
	i=n;
	cnt=0;
	while(fa[i]!=1)i=fa[i],cnt++;
	x=n;
	for(int i=1;i<=cnt/2;i++)
        x=fa[x];
    y=x;
    if(y==n)
    {
        sum1=size[y];
        sum2=n-sum1;
        if(sum2>sum1)
        cout<<"Fennec";
	else cout<<"Snuke";
            return 0;
    }
    y=fa[y];
    //printf("y=%d\n",y);
	DFS(n,0);
	sum1=size[y];
	sum2=n-sum1;
    //printf("sum1=%d,sum2=%d\n",sum1,sum2);
	if(sum1>sum2)cout<<"Fennec";
	else cout<<"Snuke";
}
