#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = (a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (a); i <= (long long)(n); i++)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<double> v_double;
typedef std::vector<std::vector<double> > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

struct Edge {
    ll cost, to;
    Edge(int to_, ll cost_) : 
        to(to_), cost(cost_) { } 
};
using Graph = vector<vector<Edge> >;

void dijkstra(Graph& g, int s, v_ll &dist, v_int &prev)
{
    int n = g.size();
    dist.assign(n, LINF);
    prev.assign(n, -1);
    priority_queue<pii, vector<pii>, greater<pii> > que;

    dist[s] = 0;
    que.push(pii(0, s));
    
    while(!que.empty()) {
        pii p = que.top(); que.pop();
        int node = p.second;
        //if(dist[node] < p.second) continue;

        for(int i = 0; i < g[node].size(); i++) {
            Edge e = g[node][i];
            if (dist[e.to] > dist[node] + e.cost) {
                dist[e.to] = dist[node] + e.cost;
                que.push(pii(dist[e.to], e.to));
                prev[e.to] = node;
            }
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    Graph node(n);

    irep(i, n-1) {
        int a, b, c;
        cin >> a >> b >> c;
        node[a-1].push_back(Edge(b-1, c));
        node[b-1].push_back(Edge(a-1, c));
    }

    int q, k;
    cin >> q >> k;

    v_ll dist(n);
    v_int prev(n);

    dijkstra(node, k-1, dist, prev);

    ll ans(q);
    irep(i, q) {
        int x, y;
        cin >> x >> y;
        cout << dist[x-1] + dist[y-1] << endl;
    }

    //irep(i, n) { cout << dist[i] << endl; }
    return 0;
}
/** atcoder **/
