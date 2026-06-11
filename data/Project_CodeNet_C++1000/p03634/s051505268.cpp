#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;

    vector<vector<pair<int, ll>>> abc(N);
    rep(i, N-1) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        abc[a].emplace_back(make_pair(b, c));
        abc[b].emplace_back(make_pair(a, c));
    }

    int Q, K; cin >> Q >> K;
    K--;

    vector<P> quer(Q);
    rep(i, Q) {
        int x, y; cin >> x >> y;
        x--; y--;
        quer[i] = make_pair(x, y);
    }

    queue<pair<int, ll>> q;
    // pair<int, ll> f;
    // f.first = K; f.second = 0;
    q.emplace(K, 0);
    vector<ll> dist(N, -1);
    dist[K] = 0;

    while (!q.empty()) {
        auto cn = q.front(); q.pop();
        // cout << "cn " << cn.first << endl;
        for (auto e: abc[cn.first]) {
            if (dist[e.first] == -1) {
                // cout << "nn " << e.first << endl;
                ll d = cn.second + e.second;
                // pair<int, ll> f;
                // f.first = e.first; f.second = d;
                // cout << "dist " << d << endl;
                q.emplace(e.first, d);
                dist[e.first] = d;
            }
        }
    }

    rep(i, Q) {
        auto xy = quer[i];
        cout << dist[xy.first] + dist[xy.second] << endl;
    }
 
    return 0;
}