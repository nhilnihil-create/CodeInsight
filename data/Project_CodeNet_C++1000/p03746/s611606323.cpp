#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    int start = -1;
    int deg = INF;
    rep(i, N) {
        if(G[i].size() < deg) {
            start = i;
            deg = G[i].size();
        }
    }
    vector<int> path;
    vector<bool> used(N, false);
    path.pb(start);
    used[start] = true;
    int now = start;
    while(1) {
        int ok = 0;
        for(auto nv : G[now]) {
            if(!used[nv]) {
                used[nv] = true;
                now = nv;
                path.pb(now);
                ok = 1;
                break;
            }
        }
        if(!ok)
            break;
    }
    reverse(All(path));
    now = start;
    while(1) {
        int ok = 0;
        for(auto nv : G[now]) {
            if(!used[nv]) {
                used[nv] = true;
                now = nv;
                path.pb(now);
                ok = 1;
                break;
            }
        }
        if(!ok)
            break;
    }
    cout << path.size() << endl;
    rep(i, path.size()) cout << path[i] + 1 << (i == N - 1 ? "\n" : " ");

    return 0;
}