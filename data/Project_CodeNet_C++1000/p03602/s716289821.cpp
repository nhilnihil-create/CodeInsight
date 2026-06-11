#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define pb push_back
#define sz(v) ((li)(v).size())
#define bgn(v) ((v).begin())
#define eend(v) ((v).end())
#define allof(v) (v).begin(), (v).end()
#define dodp(v, n) memset(v, (li)n, sizeof(v))
#define bit(n) (1ll << (li)(n))
#define mp(a, b) make_pair(a, b)
#define rin rep(i, n)
#define EPS 1e-12
#define ETOL 1e-8
#define MOD 1000000007
typedef pair<li, li> PI;

#define INF bit(60)

#define DBGP 1

#define idp if (DBGP)
#define F first
#define S second
#define p2(a, b) idp cout << a << "\t" << b << endl
#define p3(a, b, c) idp cout << a << "\t" << b << "\t" << c << endl
#define p4(a, b, c, d) idp cout << a << "\t" << b << "\t" << c << "\t" << d << endl
#define p5(a, b, c, d, e) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl
#define p6(a, b, c, d, e, f) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << endl
#define p7(a, b, c, d, e, f, g) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << endl
#define p8(a, b, c, d, e, f, g, h) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << endl
#define p9(a, b, c, d, e, f, g, h, i) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << endl
#define p10(a, b, c, d, e, f, g, h, i, j) idp cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << endl
#define foreach(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define p2p(x) idp p2((x).F, (x).S)
#define dump(x, n)                         \
    idp                                    \
    {                                      \
        rep(i, n) { cout << x[i] << " "; } \
        puts("");                          \
    }
#define dump2(x, n)                                                     \
    idp                                                                 \
    {                                                                   \
        rep(i, n) { cout << "[" << x[i].F << " , " << x[i].S << "] "; } \
        puts("");                                                       \
    }
#define dumpi(x)                  \
    idp                           \
    {                             \
        foreach (it, x)           \
        {                         \
            cout << (*it) << " "; \
        }                         \
        puts("");                 \
    }
#define dumpi2(x)                                               \
    idp                                                         \
    {                                                           \
        foreach (it, x)                                         \
        {                                                       \
            cout << "[" << (it)->F << " , " << (it)->S << "] "; \
        }                                                       \
        puts("");                                               \
    }

#define read2d(a, w, h) rep(i, h) rep(j, w) cin >> a[i][j]
#define dump2d(a, w, h)                   \
    rep(i, h)                             \
    {                                     \
        rep(j, w) cout << a[i][j] << " "; \
        puts("");                         \
    }

typedef pair<li, li> PI;

li table[333][333];
li a[333][333];

// {distance, {from, to}}
vector<pair<li, PI>> distances;
li n;

//{to, cost}
vector<PI> edges[333];

li cost_table[333];

inline li dijkstra(li from, li to) {
    rin{
        cost_table[i] = INF;
    }
    priority_queue<PI> pq;
    pq.push({0ll, from});

    while (!pq.empty()) {
        li now_cost = -pq.top().F;
        li now = pq.top().S;
        pq.pop();
        if (cost_table[now] <= now_cost) {
            continue;
        }
        cost_table[now] = now_cost;
        if (now == to) {
            return now_cost;
        }
        for (auto && edge : edges[now]) {
            if (now_cost + edge.S < cost_table[edge.F]) {
                pq.push({ -(now_cost + edge.S), edge.F});
            }
        }
    }
    return INF;
}

inline vector<li> dijkstra2(li from) {
    vector<li> res(n, INF);
    priority_queue<PI> pq;
    pq.push({0ll, from});

    while (!pq.empty()) {
        li now_cost = -pq.top().F;
        li now = pq.top().S;
        pq.pop();
        if (res[now] <= now_cost) {
            continue;
        }
        res[now] = now_cost;
        for (auto && edge : edges[now]) {
            if (now_cost + edge.S < res[edge.F]) {
                pq.push({ -(now_cost + edge.S), edge.F});
            }
        }
    }
    return res;
}

inline void update(li d, li from, li to) {
    rep(i, n) {
        table[i][to] = min(table[i][to], table[i][from] + d);
        table[i][from] = min(table[i][from], table[i][to] + d);
        table[to][i] = table[i][to];
        table[from][i] = table[i][from];
    }
}

int main(void)
{
    cin >> n;
    rin{
        rep(j, n) {
            cin >> a[i][j];
            table[i][j] = INF;
            if (i == j) {
                table[i][j] = 0;
            } else if (i < j) {
                distances.pb({a[i][j], {i, j}});
            }
        }
    }

    sort(allof(distances));
    li res = 0;

    for (auto && item : distances) {
        li d = item.F;
        li from = item.S.F;
        li to = item.S.S;
        li dist_now = dijkstra(from, to);
        if (dist_now < d) {
            puts("-1");
            return 0;
        }
        if (dist_now > d) {
            edges[from].pb({to, d});
            edges[to].pb({from, d});
            res += d;
        }
    }

    cout << res << endl;

    return 0;
}