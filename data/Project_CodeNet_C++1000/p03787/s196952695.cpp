#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// ordered_set X;
// *X.find_by_order(i) = ith largest element (counting from zero)
// X.order_of_key(k) = number of items in X < k (strict lt)

int main(){
    ll N, M;
    cin >> N >> M;

    vvi adj(N);

    for (int i=0;i<M;i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi comps(N, -1);
    vb color(N, true);
    ll num_iso = 0;
    ll num_bip = 0;

    ll ncomps = 0;
    for (int i=0;i<N;i++) {
        if (comps[i] == -1) {
            queue<int> bfs;
            bfs.push(i);
            comps[i] = ncomps;

            int cursize = 0;
            bool bi = true;

            while (!bfs.empty()) {
                int cur = bfs.front();
                bfs.pop();

                cursize++;

                for (int nbr : adj[cur]) {
                    if (comps[nbr] == -1) {
                        comps[nbr] = ncomps;
                        color[nbr] = !color[cur];
                        bfs.push(nbr);
                    } else {
                        if (color[nbr] == color[cur]) bi = false;
                    }
                }
            }

            if (cursize == 1) num_iso++;
            else if (bi) num_bip++;
            ncomps++;
        }
    }

    ncomps -= num_iso;

    ll ans = N*N - (N - num_iso)*(N - num_iso) + ncomps*ncomps + num_bip*num_bip;
    cout << ans << endl;

    return 0;
}
