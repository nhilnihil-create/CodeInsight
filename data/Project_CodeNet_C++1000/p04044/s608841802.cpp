#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    string s[n];
    rep(i, n) cin >> s[i];
    sort(s, s + n);

    string ans;
    rep(i, n) ans += s[i];

    cout << ans << endl;
    return 0;
}
