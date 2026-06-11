#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1 && a[a[i] - 1] == i + 1) {
            a[a[i] - 1] = -1;
            a[i] = -1;
            ans++;
        }
    }
    cout << ans << endl;
}