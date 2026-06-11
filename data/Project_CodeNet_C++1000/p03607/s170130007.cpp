#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#else
#define dbg(exp) /* nop; */
#endif

// F cin/cout
#define cin nullptr
#define cout nullptr

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;

int main() {
    int n;
    scanf("%d", &n);

    set<int> s;
    while (n--) {
        int x;
        scanf("%d", &x);
        if (s.count(x) == 0)
            s.insert(x);
        else
            s.erase(x);
    }

    printf("%u\n", s.size());

    return 0;
}

