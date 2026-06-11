#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mn = *min_element(a.begin(), a.end());
    if (cnt[mn] > 2) {
        cout << "Impossible" << '\n';
        return 0;
    }
    int mx = mn * 2;
    if (cnt[mn] == 2) {
        mx--;
    }
    for (int i = mn + 1; i <= mx; i++) {
        if (cnt[i] < 2) {
            cout << "Impossible" << '\n';
            return 0;
        }
    }
    for (int i = mx + 1; i < n; i++) {
        if (cnt[i]) {
            cout << "Impossible" << '\n';
            return 0;
        }
    }
    cout << "Possible" << '\n';
    return 0;
}
