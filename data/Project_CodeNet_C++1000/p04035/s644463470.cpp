#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P  = pair<int, int>;
int main() {
    int n, l, p = -1, m = 0;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m += a[i];
        if (i > 0 && a[i] + a[i - 1] >= l) p = i;
    }
    if (p < 0) return cout << "Impossible", 0;
    cout << "Possible" << endl;
    for (int i = 0; i < p - 1; ++i) cout << i + 1 << endl;
    for (int i = n - 2; i >= p; --i) cout << i + 1 << endl;
    cout << p << endl;
    return 0;
}