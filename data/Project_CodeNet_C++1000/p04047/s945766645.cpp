#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> l(2*n);
    rep(i, 2*n) cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    rep(i, n) ans += l[2*i];
    cout << ans << endl;
}