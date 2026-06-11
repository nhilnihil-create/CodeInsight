#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    int mx = 0;
    rep(i, t) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    cout << max(0, mx - 1 - k + mx) << endl;
}