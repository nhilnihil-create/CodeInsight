#include <bits/stdc++.h>

using namespace std;
using ll=long long ;

void solve() {
    int n, K;
    cin >> n >> K;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    K++;
    ll res = 0;
    int prefix = 0;
    for (int j = 30; j >= 0; j--) {
        int k = 1<<j;
        if (K & k) {
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                int x = a[i];
                x -= x&(k-1);
                if ((prefix | x) <= prefix) sum += b[i];
            }
            res = max(res, sum);
            prefix |= k;
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
