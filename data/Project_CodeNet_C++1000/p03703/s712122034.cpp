#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <class T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

ll niz[200005];
ordered_set <pair <ll, ll>> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        niz[i] -= k;
    }
    q.insert({0, 0});
    ll pre = 0;
    ll res = 0;
    for(int i=1; i<=n; i++){
        pre += niz[i];
        int k = q.order_of_key({pre, n+5});
        res += k;
        q.insert({pre, i});
    }
    cout << res;
    return 0;
}
