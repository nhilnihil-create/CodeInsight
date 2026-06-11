#include<bits/stdc++.h>
using namespace std;
long long vis[200005],dis[200005];
vector<long long>adj[200005];
void bfs(long long node)
{
    queue<long long>q;
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    while(!q.empty())
    {
        long long c=q.front();
        q.pop();
        for(auto j:adj[c])
        {
            if(!vis[j])
            {
                q.push(j);
                dis[j]=dis[c]+1;
                vis[j]=1;
            }
        }
    }
}
int main()
{
    long long T,i,j,n,m,a,b;

        cin>>n>>m;
        for(j=0;j<m;j++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(1);
        if(dis[n]==2)
            cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;

}
