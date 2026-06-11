#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#endif

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    string row[2];
    cin >> row[0];
    cin >> row[1];

    const auto get_type = [&](int i) {
        if (row[0][i] == row[1][i])
            return 1;
        else
            return 2;
    };

    int i = 0;
    int ptype = -1;
    ll ans = 1;
    while (i < n) {
        int ctype = get_type(i);
        if (ptype == -1) {
            if (ctype == 1)
                ans = 3;
            else
                ans = 6;
        } else {
            if (ptype == 1 && ctype == 1) {
                ans = (ans * 2) % MOD;
            } else if (ptype == 1 && ctype == 2) {
                ans = (ans * 2) % MOD;
            } else if (ptype == 2 && ctype == 1) {
                ans = (ans * 1) % MOD;
            } else {
                ans = (ans * 3) % MOD;
            }
        }

        ptype = ctype;

        if (ctype == 1)
            i += 1;
        else
            i += 2;
    }

    printf("%lld\n", ans);


    return 0;
}

