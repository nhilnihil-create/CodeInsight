#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 1;
    bool inc = false, dec = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1])
            inc = true;
        else if (a[i] > a[i + 1])
            dec = true;
        if (inc && dec) {
            ans++;
            inc = false;
            dec = false;
        }
    }
    cout << ans << endl;
}