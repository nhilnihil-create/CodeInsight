#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void fail() {
    cout << "NO\n";
    exit(0);
}

void go(auto& adj, vi& stones, vll& vup, int loc, int par) {
    ll tot = 0, vmax = 0;

    for (int nbr : adj[loc]) if (nbr != par) {
        go(adj, stones, vup, nbr, loc);
        tot += vup[nbr];
        vmax = max(vmax, vup[nbr]);
    }

    bool leaf = adj[loc].size() == 1;
    ll expect = leaf ? stones[loc] : 2 * stones[loc];

    if (loc == par) {
        if (tot != expect) fail();
        if (!leaf && 2 * vmax > tot) fail();
    } else {
        vup[loc] = leaf ? stones[loc] : expect - tot;
        if (vup[loc] < 0) fail();
        if (!leaf && 2 * max(vmax, vup[loc]) > expect) fail();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi stones(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }

    vvi adj(N);
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vll vup(N);
    go(adj, stones, vup, 0, 0);

    cout << "YES\n";

    return 0;
}

