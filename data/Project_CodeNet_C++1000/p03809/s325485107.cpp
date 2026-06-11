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
    int N;
    cin >> N;

    vll A(N);
    for (int i=0;i<N;i++) cin >> A[i];

    vvi adj(N);

    for (int i=0;i<N-1;i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (N == 2) {
        if (A[0] == A[1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    int rt = 0;
    while (adj[rt].size() == 1) rt++;

    vi parent(N, -1);
    vvi children(N);
    vi order;
    queue<int> bfs;

    bfs.push(rt);
    parent[rt] = rt;

    while (!bfs.empty()) {
        int cur = bfs.front();
        bfs.pop();
        
        order.push_back(cur);

        for (int nbr : adj[cur]) {
            if (parent[nbr] == -1) {
                parent[nbr] = cur;
                children[cur].push_back(nbr);
                bfs.push(nbr);
            }
        }
    }

    reverse(order.begin(), order.end());

    for (int v : order) {
        // cout << v << endl;

        if (children[v].size() == 0) continue;

        ll pstones = A[v];
        ll cstones = 0;
        
        for (int c : children[v]) cstones += A[c];

        ll b = cstones - pstones;
        ll a = pstones - b;

        // cout << pstones << " " << cstones << " " << a << " " << b << endl;

        if (a < 0 || b < 0) {
            cout << "NO" << endl;
            return 0;
        }
        
        ll mc = 0;
        for (int c : children[v]) mc = max(mc, A[c]);

        ll sc = cstones - mc;

        ll pairs = 0;
        if (mc > sc) pairs = sc;
        else pairs = cstones/2;

        if (pairs < b) {
            cout << "NO" << endl;
            return 0;
        }

        A[v] = a;
    }

    if (A[rt] == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;

}
