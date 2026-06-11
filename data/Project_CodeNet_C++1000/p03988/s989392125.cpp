// Why am I so dumb? :c
// chrono::system_clock::now().time_since_epoch().count()

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;   
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = (int)1e2 + 5;

int arr[MAXN], cnt[MAXN];

int n;

void bye(bool x = 0) {
    printf(x ? "Possible\n" : "Impossible\n");
    exit(0);
}

void solve() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        ++cnt[arr[i]];
    }

    int D = *max_element(arr + 1, arr + n + 1);
    int R = (D + 1) / 2;

    if (*min_element(arr + 1, arr + n + 1) < R) {
        bye();
    }

    if (D % 2 == 0) {
        if (cnt[R] != 1) {
            bye();
        }
    }
    else {
        if (cnt[R] != 2) {
            bye();
        }
    }

    for (int i = R; i <= D; ++i) {
        if (cnt[i] == 0) {
            bye();
        }       
    }                                                                

    bye(1);
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}
