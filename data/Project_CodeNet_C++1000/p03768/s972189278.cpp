#include<bits/stdc++.h>
using namespace std;

#define iii pair<pair<int,int>,int> 
#define FIR first.first
#define SEC first.second
#define THI second

int N,M;
vector<int> e[100010];
int Q;
iii q[100010];

int g[100010];
int maxd[100010];

void input()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		maxd[i]=-1;
	}
	for(int i=1,tmp1,tmp2;i<=M;i++)
	{
		scanf("%d%d",&tmp1,&tmp2);
		e[tmp1].push_back(tmp2);
		e[tmp2].push_back(tmp1);
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d%d",&q[i].FIR,&q[i].SEC,&q[i].THI);
	}
}

void f(int v,int d,int c)
{
	if(d<=maxd[v])
	{
		return;
	}
	maxd[v]=d;
	
	if(g[v]==0) g[v]=c;
	for(int i=0;i<e[v].size();i++)
	{
		f(e[v][i],d-1,c);
	}
}

void work()
{
	for(int i=Q;i>=1;i--)
	{
		f(q[i].FIR,q[i].SEC,q[i].THI);
	}
}

void output()
{
	for(int i=1;i<=N;i++)
	{
		printf("%d\n",g[i]);
	}
}

int main()
{
	input();
	work();
	output();
	return 0;
}
