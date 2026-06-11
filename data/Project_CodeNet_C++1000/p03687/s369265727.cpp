#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(26, 0), d(26, 0);
    for (int i = n - 1; i >= 0; i--) {
        rep(j, 26) {
            c[j]++;
            if (s[i] - 'a' == j) c[j] = 0;
            d[j] = max(d[j], c[j]);
        }
    }
    int ans = n;
    rep(i, 26) ans = min(ans, d[i]);
    cout << ans << "\n";
    //rep(i, 26) cout << d[i] << "\n";
}