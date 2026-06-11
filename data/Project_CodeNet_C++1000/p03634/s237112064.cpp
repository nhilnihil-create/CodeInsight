#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
#define INF 1e+14

struct edge
{
    ll to;
    ll cost;
};

vector<ll> dist(100010, INF);
vector<vector<edge>> G(100010, vector<edge>());

void dijkstra(const vector<vector<edge>> &G, int s)
{
    priority_queue<Pl, vector<Pl>, greater<Pl>> que;
    dist[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        Pl p1 = que.top();
        que.pop();
        ll v = p1.second;
        if (dist[v] < p1.first)
            continue;

        for (auto e : G[v])
        {
            if (dist[e.to] > dist[v] + e.cost)
            {
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<edge>> G(N);
    REP(i,N-1) {
        ll a,b,c; cin >> a >> b >> c;
        --a; --b;
        G[a].push_back(edge{b, c});
        G[b].push_back(edge{a, c});
    }
    ll Q,K; cin >> Q >> K;
    K--;
    dijkstra(G, K);
    REP(i, Q)
    {
        ll x, y; cin >> x >> y;
        --x; --y;
        cout << dist[x] + dist[y] << endl;
    }
}