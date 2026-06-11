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

ll n, k, ret;
vector<vector<int>> G;

bool used[100009];

int dfs(int v) {
    used[v] = true;
    int res = 0;
    for(int u : G[v]) {
        if(!used[u]) {
            int x = dfs(u);
            if(x < k)
                chmax(res, x);
            else if(v)
                ret++;
        }
    }
    return res + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    G.resize(n);

    rep(i, n) {
        int a;
        cin >> a;
        a--;
        if(i == 0)
            ret += (a ? 1 : 0);
        else
            G[a].push_back(i);
    }

    dfs(0);

    cout << ret << endl;

    return 0;
}