#include<bits/stdc++.h>
using namespace std;
#define MAXV 2005
int n,k;
vector<int>edges[MAXV];
int vis[MAXV],level_num[MAXV],ans;
void addedge(int from,int to)
{
        edges[from].push_back(to);
        edges[to].push_back(from);
}
void dfs(int now,int n)
{
        vis[now] = 1;
        level_num[n]++;
        for(int i=0;i<edges[now].size();i++)
        {
                int v = edges[now][i];
                if(!vis[v])
                {
                        //cout<<v<<endl;
                        dfs(v,n+1);
                }
        }
}
int main ()
{
        int from,to,temp;
        cin>>n>>k;
        ans = 0x3f3f3f3f;
        for(int i=0;i<n-1;i++)
        {
                cin>>from>>to;
                addedge(from,to);
        }
        if(k%2)
        {
                for(int i=1;i<=n;i++)
                {

                        for(int j=0;j<edges[i].size();j++)
                        {
                                temp = 0;
                                memset(level_num,0,sizeof(level_num));
                                memset(vis,0,sizeof(vis));

                                vis[edges[i][j]] = 1;
                                dfs(i,0);
                                dfs(edges[i][j],0);
//                                cout<<"////////////"<<i<<"///////"<<edges[i][j]<<endl;
//                                for(int ii=0;ii<=6;ii++)
//                                {
//                                        cout<<ii<<" "<<level_num[ii]<<endl;
//                                }
                                for(int ii=(k-1)/2 + 1;ii<=n;ii++)
                                {
                                        if(!level_num[ii])        break;
                                        temp += level_num[ii];
                                }
                                ans = min(ans,temp);
                        }
                }
        }
        else
        {
                for(int i=1;i<=n;i++)
                {
                        temp = 0;
                        memset(level_num,0,sizeof(level_num));
                        memset(vis,0,sizeof(vis));
                        dfs(i,0);
                        for(int j=k/2 + 1 ;j<=n;j++)
                        {
                                if(!level_num[j])        break;
                                temp += level_num[j];
                        }
                        ans = min(ans,temp);
                }
        }
        cout<<ans<<endl;


}
