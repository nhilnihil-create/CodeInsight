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

constexpr int MAXD = 10;

int main(){
    int N, M;
    cin >> N >> M;

    vvi adj((MAXD+1)*N);

    for (int i=0;i<M;i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        for (int d=1;d<=MAXD;d++) {
            adj[d*N + a].push_back((d-1)*N + b);
            adj[d*N + b].push_back((d-1)*N + a);
        }
    }

    for (int i=0;i<N;i++) {
        for (int d=1;d<=MAXD;d++) {
            adj[d*N + i].push_back((d-1)*N + i);
        }
    }

    vi colors((MAXD+1)*N, 0);

    int Q;
    cin >> Q;
    vi qvs(Q);
    vi qcs(Q);
    vi qds(Q);

    for (int i=0;i<Q;i++) cin >> qvs[Q-1-i] >> qds[Q-1-i] >> qcs[Q-1-i];

    for (int i=0;i<Q;i++) {
        int col = qcs[i];
        int d = qds[i];
        int v = qvs[i];
        v--;

        if(colors[d*N + v] != 0) continue;

        queue<int> bfs;
        bfs.push(d*N + v);
        colors[d*N + v] = col;

        while (!bfs.empty()) {
            int cur = bfs.front();
            bfs.pop();

            for (int nbr : adj[cur]) {
                if (colors[nbr] == 0) {
                    colors[nbr] = col;
                    bfs.push(nbr);
                }
            }
        }
    }

    for (int i=0;i<N;i++) cout << colors[i] << "\n";

    return 0;
}
