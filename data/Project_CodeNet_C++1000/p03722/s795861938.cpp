#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

const ll INF = (ll)1e18 + 9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<ll> dist(n, -INF);
    dist[0] = 0;
    ll ans = 0;
    
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }
    
    rep(i, n - 1) {
        rep(ii, n) {
            for (auto edge : g[ii]) {
                dist[edge.first] = max(dist[edge.first], dist[ii] + edge.second);
            }
        }
    }
    
    rep(i, n - 1) {
        rep(ii, n) {
            for (auto edge : g[ii]) {
                if ((dist[ii] == INF) || (dist[edge.first] < (dist[ii] + edge.second))) {
                    dist[edge.first] = INF;
                }
            }
        }
    }
    
    ans = dist[n - 1];
    
    if (ans == INF) {
        cout << "inf" << endl;
    }
    else {
        cout << ans << endl;
    }
    
    return 0;
}
