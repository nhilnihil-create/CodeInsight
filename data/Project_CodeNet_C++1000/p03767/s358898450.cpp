#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> a(3*n);
    rep(i, 3*n) cin >> a[i];
    sort(a.begin(), a.end());
    Int ans = 0;
    for (int i = n; i < n*3; i+=2) {
        ans += (Int)a[i];
    }
    cout << ans << endl;
}