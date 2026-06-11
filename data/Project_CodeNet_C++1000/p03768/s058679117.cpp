#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(1e5) + 2;
typedef tuple<int, int, int> TQuery;

int color[N][11], n, m, Q, u, v, d, c;
TQuery q[N];
vector<int> a[N];

void Paint(int u, int d) {
    if(color[u][d]) return;
    color[u][d] = c;
    if(d == 0) return;
    Paint(u, d - 1);
    for(int v: a[u]) Paint(v, d - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        a[u].pb(v), a[v].pb(u);
    }
    cin >> Q;
    for(int i = 1; i <= Q; ++i) {
        cin >> v >> d >> c;
        q[i] = make_tuple(v, d, c);
    }
    for(int i = Q; i >= 1; --i) {
        tie(v, d, c) = q[i];
        Paint(v, d);
    }
    for(int i = 1; i <= n; ++i) cout << color[i][0] << '\n';
}
