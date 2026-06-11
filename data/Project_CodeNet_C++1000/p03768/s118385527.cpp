#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int n,m,q,x,y;
vector <int> g[100005];
int a[100005],b[100005],c[100005],res[100005];
int misd[100005];
void dfs(int node,int Cin,int Din)
{
	if(Din<=misd[node])
	    return;
	misd[node]=Din;
	if(res[node]==0)
	    res[node]=Cin;
	if(Din==0)
	    return;
	for(int i=0;i<g[node].size();i++)
	    dfs(g[node][i],Cin,Din-1);
}
int main() 
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--,y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	    misd[i]=-1;
	scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
    	scanf("%d%d%d",&a[i],&b[i],&c[i]);
    	a[i]--;
	}
	for(int i=q-1;i>=0;i--)
	    dfs(a[i],c[i],b[i]);
	for(int i=0;i<n;i++)
	    printf("%d\n",res[i]);
	return 0;
}