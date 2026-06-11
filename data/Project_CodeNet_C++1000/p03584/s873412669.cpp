#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    ll ans = 0;
    k++;
    while (k) {
        k--;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if ((p[i].first | k) == k) sum += p[i].second;
        }
        ans = max(ans, sum);
        k = (k & (k + 1));
    }
    cout << ans << endl;
    return 0;
}