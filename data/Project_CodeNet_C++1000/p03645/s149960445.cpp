#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int>adj[MAX];
int v[MAX],dist[MAX];
void bfs(int src)
{
    v[src] = 1;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int i=0; i<adj[parent].size(); i++)
        {
            int child = adj[parent][i];
            if(v[child] == 0)
            {
                v[child]=1;
                dist[child]=dist[parent]+1;
                q.push(child);
            }
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bfs(1);
    if(dist[n]<=2 && v[n])
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
