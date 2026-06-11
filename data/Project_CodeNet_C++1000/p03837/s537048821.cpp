#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <queue>
#define INFL 1000000000000000

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

vector< vector<ll> > from;

vector<ll> dijkstra(ll s, vector< map<ll, ll> > e) {
    ll n = e.size();
    vector<ll> minD(n, INFL);
    minD.at(s) = 0;
    priority_queue< pl, vector<pl>, greater<pl> > q;
    q.push(pl(0, s));
    while (!q.empty()) {
        pl now = q.top();
        q.pop();
        ll c = now.first, v = now.second;
        if (minD.at(v) < c) continue;
        for (auto i = e.at(v).begin(); i != e.at(v).end(); ++i) {
            ll nv = i -> first, nc = i -> second;
            if (minD.at(nv) > minD.at(v) + nc) {
                minD.at(nv) = minD.at(v) + nc;
                from.at(s).at(nv) = v;
                q.push(pl(minD.at(nv), nv));
            }
        }
    }
    return minD;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, a, b, c;
    cin >> n >> m;
    vector< map<ll, ll> > e(n + 1);
    from = vector< vector<ll> >(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < m; ++i) cin >> a >> b >> c, e.at(a)[b] = c, e.at(b)[a] = c;
    for (int i = 1; i <= n; ++i) dijkstra(i, e);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) e.at(from.at(i).at(j)).erase(j);
    cout << (accumulate(e.begin(), e.end(), 0LL, [](ll i, map<ll, ll> j) {
        return i += j.size();
    }) / 2) << endl;
    return 0;
}
