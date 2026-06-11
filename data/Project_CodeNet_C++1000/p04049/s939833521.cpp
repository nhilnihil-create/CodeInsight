#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2005;
vector<int>v[N];
int n,m,a,b,dist[N][N];
inline bool cmp(vector<int>x,vector<int>y){return x.size()>y.size();}
void bfs()
{
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)dist[i][j]=1e9;
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        q.push(0);
        q.push(i);
        q.push(i);
    }
    while(!q.empty())
    {
        int move=q.front();q.pop();
        int org=q.front();q.pop();
        int now=q.front();q.pop();
        if(dist[org][now]<=move)continue;
        dist[org][now]=move;
        for(int i=0;i<v[now].size();i++)
        {
            int to=v[now][i];
            q.push(move+1);
            q.push(org);
            q.push(to);
        }
    }

}
void solve()
{
    bfs();
    int pnt=0,ans=0;
    vector<int>e[N];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dist[i][j]>m)
                e[i].pb(j),pnt++;
    for(int i=0;i<n;i++)sort(e[i].begin(),e[i].end());
    while(pnt)
    {
        int MAX=0,num=-1;
        for(int i=0;i<n;i++)
        {
            if(MAX<e[i].size())
            {
                num=i;
                MAX=e[i].size();
            }
        }
        for(int i=0;i<e[num].size();i++)
        {
            int to=e[num][i];
            e[to].erase(lower_bound(e[to].begin(),e[to].end(),num));
        }
        ans++;
        pnt-=e[num].size()*2;
        e[num].clear();
    }
    cout<<ans<<endl;
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        a--,b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    solve();
    return 0;
}