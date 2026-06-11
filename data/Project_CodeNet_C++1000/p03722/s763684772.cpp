#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

typedef long long ll;

#define MAX_N 10000
#define ORD_MONEY 1000000000000000

struct Edge {
    int from;
    int to;
    ll cost;
    Edge(int f, int t, ll c)
        : from(f)
        , to(t)
        , cost(c)
    {
    }
};
using Graph = vector<vector<int>>;
using Graph_e = vector<vector<Edge>>;

vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };
typedef pair<int, int> P; // first:最短距離，second:頂点番号

typedef pair<ll, ll> P_dij;

ll dijkstra(int s, int g, Graph_e G)
{
    ll d[110];
    fill(d, d + 110, INF_64);
    d[s] = 0;

    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto e : G.at(v)) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    if (d[g] != INF_64) {
        return d[g];
    } else {
        return -1;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Edge> edge;
    vector<ll> d(N, INF_64);
    vector<bool> negative(N, false);
    d.at(0) = 0;

    rep(i, M)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        edge.push_back(Edge(a, b, -c));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Edge e = edge.at(j);

            if (d.at(e.to) > d.at(e.from) + e.cost) {
                d.at(e.to) = d.at(e.from) + e.cost;
                if (i == N - 1) {
                    negative.at(e.to) = true;
                }
            }
        }
    }

    rep(i, M)
    {
        if (negative.at(edge.at(i).from) == true) {
            negative.at(edge.at(i).to) = true;
        }
    }

    if (negative.at(N - 1)) {
        cout << "inf" << endl;
    } else {
        cout << -d.at(N - 1) << endl;
    }
    return 0;
}
