#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}

struct edge
{
    long long to, cost;
};
using P = pair<int, int>;
int V;
const int MAX_V = 201;

vector<edge> G[MAX_V];


vll dijkstra(int start)
{
    vector<long long> d(MAX_V, INT_MAX);
    priority_queue<P, vector<P>, greater<P>> que;
    d[start] = 0;
    que.push(P(0, start));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        long long v = p.second;
        if (d[v] < p.first)
        {
            continue;
        }
        for (int i = 0; i < G[v].size(); i++)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}
int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    vint r(R);
    int perm[R];
    for (size_t i = 0; i < R; i++)
    {
        cin >> r[i];
        perm[i] = i;
        r[i]--;
    }
    int a, b, c;
    for (size_t i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].emplace_back(edge{b, c});
        G[b].emplace_back(edge{a, c});
    }
    ll ans = INF;
    vvll dist = make_v<ll>(N,N); // dist [{a,b}] := aからbへの距離
    for (size_t i = 0; i < R; i++)
    {
        auto d = dijkstra(r[i]);
        for (size_t j = 0; j < R; j++)
        {
            dist[r[i]][r[j]]=d[r[j]];
        }
        
    }
    
    do
    {
        ll d = 0;
        for (size_t i = 0; i < R-1; i++)
        {
            d += dist[r[perm[i]]][r[perm[i+1]]];
        }
        chmin(ans,d);
    } while (next_permutation(perm,perm+R));
    cout<<ans;
    return 0;
}