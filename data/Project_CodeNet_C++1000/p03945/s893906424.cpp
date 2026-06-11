#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;

    char now = s[0];
    int ans = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != now) {
            ans++;
            now = s[i];
        }
    }

    cout << ans << endl;

    return 0;
}