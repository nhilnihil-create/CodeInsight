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

int main() {
    int n;
    cin >> n;

    map<int, int> M;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;

        if (M.count(x) == 0)
            M[x] = 0;
        M[x] ++;
    }

    vector<ll> arr;
    for (auto p : M)
        if (p.second > 1)
            arr.push_back(p.first);

    reverse(begin(arr), end(arr));
    if (arr.empty()) {
        cout << "0\n";
    } else if (M[arr[0]] >= 4) {
        cout << arr[0] * arr[0] << '\n';
    } else {
        cout << arr[0] * arr[1] << '\n';
    }

    return 0;
}

