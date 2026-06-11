#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#else
#define dbg(exp) /* nop; */
#endif

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int main() {
    int x, t;
    cin >> x >> t;

    if (x > t) {
        cout << (x - t) << '\n';
    } else {
        cout << "0\n";
    }

    return 0;
}

