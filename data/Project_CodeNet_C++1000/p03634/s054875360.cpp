#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
const int MAX_V = 200000;
struct edge
{
    ll to;
    ll cost;
};
vector<vector<edge>> G(MAX_V);
vector<ll> dijkstra(ll s, ll N)
{
    vector<ll> value(N, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    value[s] = 0;
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (value[v] < p.first)
        {
            continue;
        }
        rep(i, G[v].size())
        {
            edge e = G[v][i];
            if (value[e.to] > value[v] + e.cost)
            {
                value[e.to] = value[v] + e.cost;
                que.push(P(value[e.to], e.to));
            }
        }
    }

    return value;
}

int main()
{
    int N;
    cin >> N;
    rep(i, N - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    
    int Q, K;
    cin >> Q >> K;
    K--;

    vector<ll> res = dijkstra(K, N);
    rep(i, Q) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << res[x] + res[y] << endl;
    }
    
    return 0;
}