#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
typedef long long ll;
typedef pair<ll, ll> P;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)
vector<long long> dijkstra(vector<vector<pair<long long, long long>>> graph, long long s) {
    vector<long long> ans(graph.size(), -1);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>
        pq;
    pq.push({0, s});
    while (pq.size() > 0) {
        ll cur1 = 0;
        ll cur2 = 0;
        if (ans[pq.top().second] != -1) {
            pq.pop();
        } else {
            cur1 = pq.top().first;
            cur2 = pq.top().second;
            pq.pop();
            ans[cur2] = cur1;
            for (long long i = 0; i < graph[cur2].size(); i++) {
                pq.push({cur1 + graph[cur2][i].second, graph[cur2][i].first});
            }
        }
    }
    return ans;
}
const ll INF = 1LL << 60;
void bellman_ford(vector<vector<P>> &edge, vector<ll> &dist, vector<bool> &loop, int s) {
    int n = edge.size();
    dist.resize(n, INF);
    dist[s] = 0;
    for (int i = 1; i < n; i++) {
        for (int from = 0; from < n; from++) {
            if (dist[from] == INF) continue;
            for (P e : edge[from]) {
                int to = e.first;
                dist[to] = min(dist[to], dist[from] + e.second);
            }
        }
    }

    loop.resize(n, false);
    for (int i = 0; i < n; i++) {
        for (int from = 0; from < n; from++) {
            if (dist[from] == INF) continue;
            for (P &e : edge[from]) {
                int to = e.first;
                if (dist[to] > dist[from] + e.second) {
                    dist[to] = dist[from] + e.second;
                    loop[from] = true;
                    loop[to] = true;
                }
            }
        }
    }
}
int main() {
    ll n, m, t;
    cin >> n >> m;
    vector<vector<P>> graph(n);
    vector<ll> dist;
    vector<bool> loop;
    REP(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -1 * c;
        graph[a].push_back({b, c});
    }
    bellman_ford(graph, dist, loop, 0);
    if (loop[n - 1] == true) {
        cout << "inf" << endl;
    } else {
        cout << -1 * dist[n - 1] << endl;
    }
}