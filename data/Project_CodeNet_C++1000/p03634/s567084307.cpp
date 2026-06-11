#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int, int> pint;
#define mp make_pair
const ll INF = 1001001001001001001;

int main() {
    int n;
    cin >> n;
    vector<vector<pint>> graph(n, vector<pint>(0));
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        graph[a].emplace_back(mp(c, b));
        graph[b].emplace_back(mp(c, a));
    }
    int q, k;
    cin >> q >> k;
    --k;
    vector<int> x(q), y(q);
    for (int i = 0; i < q; ++i) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<ll> dist(n, INF);
    pq.push(mp(0, k));
    dist[k] = 0;
    while (!pq.empty()) {
        pint v = pq.top();
        pq.pop();
        for (pint i : graph[v.second]) {
            if (dist[i.second] > dist[v.second] + i.first) {
                dist[i.second] = dist[v.second] + i.first;
                pq.push(mp(dist[i.second], i.second));
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << dist[x[i]] + dist[y[i]] << endl;
    }
}
