#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> l(n);
    rep(i, n) { cin >> l.at(i); }
    sort(l.rbegin(), l.rend());
    rep(i, k) { ans += l.at(i); }
    cout << ans << endl;
    return 0;
}