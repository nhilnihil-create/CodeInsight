#include "bits/stdc++.h"
using namespace std;
typedef long long li;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n, l, t;
    cin >> n >> l >> t;

    vector<li> xs(n), vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> vs[i];
        if (vs[i] == 2) {
            vs[i] = -1;
        }
    }

    li swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (vs[i] == vs[0]) {
            continue;
        }
        li offset;
        if (vs[0] == 1) {
            offset = xs[i] - xs[0];
        } else {
            offset = xs[0] + (l - xs[i]);
        }

        swaps += (2 * t + l - offset) / l;
    }
    swaps %= n;

    li zero_owner;
    if (vs[0] == 1) {
        zero_owner = swaps;
    } else {
        zero_owner = (n - swaps) % n;
    }

    vector<li> results(n);
    for (int i = 0; i < n; ++i) {
        results[i] = ((xs[i] + t * vs[i]) % l + l) % l;
    }

    li zero_pos = results[0];
    sort(results.begin(), results.end());

    li owner_index;
    if (vs[0] == 1) {
        owner_index = (upper_bound(results.begin(), results.end(), zero_pos) - results.begin()) - 1;
    } else {
        owner_index = lower_bound(results.begin(), results.end(), zero_pos) - results.begin();
    }
    // results[owner_index] = ans[zero_owner]

    for (int i = 0; i < n; ++i) {
        int j = (i + owner_index - zero_owner + n) % n;
        cout << results[j] << endl;
    }

    return 0;
}