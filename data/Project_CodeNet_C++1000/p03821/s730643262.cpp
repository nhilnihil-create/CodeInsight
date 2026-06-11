#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    Int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        Int aa = ans + a[i];
        Int tmp = (Int)aa % b[i];
        if (tmp == 0) continue;
        //cout << ((Int)b[i] - tmp) << endl;
        ans += ((Int)b[i] - tmp);
    }   
    cout << ans << endl;
}