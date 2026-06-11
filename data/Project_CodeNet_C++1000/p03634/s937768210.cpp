#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

using Pint = pair<ll, int>;
vector<vector<Pint>> g (100005);
int n;
ll seen[100005];
void dijkstra (int k) {
    priority_queue<Pint, vector<Pint>, greater<Pint>> pq;
    rep (i, 0, n) seen[i] = INF;
    seen[k] = 0;
    pq.push ({0, k});
    while (!pq.empty()) {
        Pint p = pq.top();
        pq.pop();
        int v = p.second;
        if (seen[v] < p.first) continue;

        rep (i, 0, g[v].size()) {
            Pint q = g[v][i];
            if (seen[q.second] > seen[v] + q.first) {
                seen[q.second] = seen[v] + q.first;
                pq.push ({seen[q.second], q.second});
            }
        }
    }
}

int main() {
    cin >> n;
    rep (i, 0, n - 1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[--a].push_back ({c, --b});
        g[b].push_back ({c, a});
    }
    int q, k;
    cin >> q >> k;
    dijkstra (--k);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << seen[--a] + seen[--b] << "\n";
    }
    // rep (i, 0, n) cout << seen[i] << "\n";
}