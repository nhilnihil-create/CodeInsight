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
typedef long long ll;
typedef pair<ll, ll> P;
#define REP(i, n) for (long long i = 0; i < (n); i++)
const ll INF = 1LL << 60;
vector<vector<ll>> adj;
bool warfloyd(vector<vector<ll>> graph) {
    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    REP(i, graph.size()) {
        if (adj[i][i] != 0) {
            return true;
        }
    }
    return false;
}
int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> city(r);
    vector<int> save(r);
    REP(i, r) {
        cin >> city[i];
        city[i]--;
    }
    save = city;
    next_permutation(city.begin(), city.end());
    adj.resize(n, vector<ll>(n, INF));
    REP(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    warfloyd(adj);
    int mn = 1e9;
    while (city != save) {
        int sum = 0;
        REP(i, city.size() - 1) { sum += adj[city[i]][city[i + 1]]; }
        mn = min(sum, mn);
        // for (auto x : city) {
        //     cout << x + 1;
        // }
        // cout << endl;
        // cout << sum << endl;
        next_permutation(city.begin(), city.end());
    }
    int sum = 0;
    REP(i, save.size() - 1) { sum += adj[save[i]][save[i + 1]]; }
    mn = min(sum, mn);
    cout << mn << endl;
}