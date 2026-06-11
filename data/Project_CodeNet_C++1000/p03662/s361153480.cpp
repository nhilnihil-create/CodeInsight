#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int MAX_N = 100100;
class edge
{
    public:
        int to, cost;
};
vector<edge> G[MAX_N];
int d[MAX_N];
int n;
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    for(int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty())
    {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if(d[e.to] <= d[v] + e.cost) continue;
            d[e.to] = d[v] + e.cost;
            que.push(P(d[e.to], e.to));
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;    
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back({b, 1});
        G[b].push_back({a, 1});
    }
    int f_cost[n + 1], s_cost[n + 1];
    dijkstra(0);
    for(int i = 0; i < n; i++) f_cost[i] = d[i];
    dijkstra(n - 1);
    for(int i = 0; i < n; i++) s_cost[i] = d[i];
    int fcnt = 0, scnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(f_cost[i] <= s_cost[i]) fcnt++;
        else scnt++;
    }
    cout << (fcnt <= scnt ? "Snuke" : "Fennec") << endl;
    return 0;
}