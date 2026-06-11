#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define pw(x) (1LL << (x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

struct edge
{
    int to, cost;
};

void dijkstra(int s, int n, vector<vector<edge>> &G, vector<vector<bool>> &used)
{
    vector<int> d(n, INT_MAX);
    typedef pair<int, int> P; // first->shortest dist, second->vertex number
    priority_queue<P, vector<P>, greater<P>> pq;
    d.at(s) = 0;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (d.at(v) < p.first)
            continue;
        for (int i = 0; i < G.at(v).size(); ++i)
        {
            edge e = G.at(v).at(i);
            if (d.at(e.to) > d.at(v) + e.cost)
            {
                d.at(e.to) = d.at(v) + e.cost;
                pq.push(P(d.at(e.to), e.to));
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < G.at(i).size(); ++j)
        {
            edge e = G.at(i).at(j);
            if (d.at(i) + e.cost == d.at(e.to))
            {
                used.at(i).at(e.to) = true;
                used.at(e.to).at(i) = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<edge>> G(N);

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.at(a - 1).push_back({b - 1, c});
        G.at(b - 1).push_back({a - 1, c});
    }

    vector<vector<bool>> used(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i)
        dijkstra(i, N, G, used);

    int ans = M;
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            if (used.at(i).at(j))
                --ans;

    cout << ans << '\n';

    return 0;
}