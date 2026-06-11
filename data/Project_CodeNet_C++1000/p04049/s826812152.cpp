#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stack>
#define pii std::pair<int,int>
using namespace std;

vector<int> edge[2005];
pair<int,int> e[2005];
bool vis[2005];
int cnt;

void dfs(int n,int k)
{
    vis[n]=1;cnt++;
    if(k==0) 
		return;
    for(int i=0;i<edge[n].size();i++)
        if(!vis[edge[n][i]]) 
			dfs(edge[n][i],k-1);
}
int main(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n-1;i++)
	{
        int a,b;
		cin>>a>>b;
        e[i].first=a;
		e[i].second=b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int ans=n;
    if(k&1)
	{
        for(int i=1;i<=n-1;i++)
		{
            cnt=0;
            memset(vis,0,sizeof vis);
            vis[e[i].second]=1;
            dfs(e[i].first,k/2);
            dfs(e[i].second,k/2);
            int tmp=n-cnt;
            ans=min(tmp,ans);
        }
    }
	else
	{
        for(int i=1;i<=n;i++)
		{
            cnt=0;
            memset(vis,0,sizeof vis);
            dfs(i,k/2);
            int tmp=n-cnt;
            ans=min(tmp,ans);
        }
    }
    cout<<ans<<endl;
}