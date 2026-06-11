/*
date 2018-__-__
time:from:  to:
problem's name:
statue:
writer:Patrick_y
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define mp make_pair
typedef long long ll;
using namespace std;
const int INF=20050226;
/*------------main part------------*/



vector<int> edg[100005];
int dis2[100005];
bool vis[100005];
int num1,num2;
int dis[100005];
void dfs(int x)
{
	if(vis[x])
		return;
	vis[x]=true;
	for(int i=0;i<edg[x].size();i++)
	{
		if(dis[edg[x][i]]>dis[x]+1)
		{
			dis[edg[x][i]]=dis[x]+1;
			dfs(edg[x][i]);
		}
	}
}
void df2(int x)
{
	if(vis[x])
		return;
	vis[x]=true;
	for(int i=0;i<edg[x].size();i++)
	{
		if(dis2[edg[x][i]]>dis[x]+1)
		{
			dis2[edg[x][i]]=dis2[x]+1;
			df2(edg[x][i]);
		}
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		edg[x].push_back(y);
		edg[y].push_back(x); 
	}
	for(int i=0;i<=n;i++)
	{
		dis2[i]=dis[i]=INF;
	}
	dis[1]=0;
	dfs(1);
	memset(vis,0,sizeof(vis));
	dis2[n]=0;
	df2(n);
	for(int i=1;i<=n;i++)
	{
		if(dis[i]<=dis2[i])
		{
			num1++;
		}
		else
		{
			num2++;
		}
	}
	if(num1>num2)
	{
		cout<<"Fennec";
	}
	else
	{
		cout<<"Snuke";
	}
	return 0;
}