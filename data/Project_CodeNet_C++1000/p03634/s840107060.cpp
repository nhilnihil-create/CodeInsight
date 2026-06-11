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
ll cost[MAX];
vector< pair <ll,int> >graph[MAX];
void dijkstra(int src)
{
    priority_queue< pair<int,int> >q;
    q.push(make_pair(0,src));
    cost[src]=0;
    while(!q.empty())
    {
        ll parents_money=q.top().first*-1;
        int parent=q.top().second;
        q.pop();
        for(int i=0; i<graph[parent].size(); i++)
        {
            ll childs_money=graph[parent][i].first;
            int child=graph[parent][i].second;
            if(cost[child]==-1 || cost[child]>childs_money+cost[parent])
            {
                cost[child]=childs_money+cost[parent];
                q.push(make_pair(-1*cost[child],child));
            }
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    memset(cost,-1,sizeof(cost));
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        graph[u].push_back({c,v});
        graph[v].push_back({c,u});
    }
    int q,k;
    cin>>q>>k;
    dijkstra(k);
    while(q--)
 {
     int x,y;
     cin>>x>>y;
     cout<<cost[x]+cost[y]<<endl;
 }
    return 0;
}
