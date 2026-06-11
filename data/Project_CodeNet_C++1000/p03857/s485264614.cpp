#include<iostream>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
const int N = 2e5;
vector<int> adj1[N+1];
vector<int> adj2[N+1];
int color[N+1];
void dfs1(int u, int c)
{
    color[u] = c;
    for(const int& v : adj1[u])
        if(color[v]==-1)
            dfs1(v,c);
}
int ans[N+1];
bool vis[N+1];
set<int> has_answer;
vector<int> cc[N+1];
void dfs2(int u)
{
    vis[u] = true;
    has_answer.insert(color[u]);
    cc[color[u]].push_back(u);

    for(const int& v : adj2[u])
        if(!vis[v])
            dfs2(v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, l; cin >> n >> k >> l;
    for(int i = 0; i < k; i++)
    {
        int u, v; cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    for(int i = 0; i < l; i++)
    {
        int u, v; cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    memset(color,-1,sizeof color);
    int sz = 0;
    for(int u = 1; u <= n; u++)
        if(color[u]==-1)
            dfs1(u,++sz);

    memset(vis,false,sizeof vis);
    for(int u = 1; u <= n; u++)
        if(!vis[u])
        {
            dfs2(u);
            for(const int& c : has_answer)
            {
                for(const int& v : cc[c])
                    ans[v] = cc[c].size();
                vector<int>().swap(cc[c]);
            }
            set<int>().swap(has_answer);
        }
    for(int u = 1; u <= n; u++)
        cout<<ans[u]<<" ";
    cout<<endl;

    cout<<flush;
    return 0;
}