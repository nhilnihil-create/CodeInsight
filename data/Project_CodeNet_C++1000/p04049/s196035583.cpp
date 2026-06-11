#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,res;
vector<int>v[2001],vv;
bool vis[2001];
void dfs(int x,int len)
{
    res++;
    if(len==0){vv.push_back(x);return;}
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]]) vis[v[x][i]]=true,dfs(v[x][i],len-1),vis[v[x][i]]=false;
}
int dfss(int x,int len)
{
    if(len==0) return 1;;
    int ans=0;
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]]) vis[v[x][i]]=true,ans+=dfss(v[x][i],len-1),vis[v[x][i]]=false;
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        res=0;
        vis[i]=true;
        vv.clear();
        dfs(i,k/2);
        if(k%2==1)
        {
            int ma=0;
            for(int j=0;j<v[i].size();j++)
            {
                vis[v[i][j]]=true;
                ma=max(ma,dfss(v[i][j],k/2));
                vis[v[i][j]]=false;
            }
            res+=ma;
        }
        vis[i]=false;
        ans=max(ans,res);
    }
    printf("%d\n",n-ans);
}
