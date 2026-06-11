#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int N, M, Q;
vector<vector<int>> G, ans;

void f(int v, int d, int c) {
    int i = d;
    while(i >= 0 && ans[v][i] == 0)
        ans[v][i--] = c;
    if(i != d)
        for(int u : G[v])
            f(u, d - 1, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    G.resize(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cin >> Q;
    vector<int> v(Q), d(Q), c(Q);
    rep(i, Q) {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    ans.assign(N, vector<int>(11));
    while(Q--)
        f(v[Q], d[Q], c[Q]);

    rep(i, N) cout << ans[i][0] << endl;

    return 0;
}