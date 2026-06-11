#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 1;
    int stat = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == a[i]) {
            continue;
        } else if (a[i - 1] > a[i]) {
            if (stat == 0)
                stat = -1;
            if (stat != -1) {
                ++ans;
                stat = 0;
            }
        } else {
            if (stat == 0)
                stat = 1;
            if (stat != 1) {
                ++ans;
                stat = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}