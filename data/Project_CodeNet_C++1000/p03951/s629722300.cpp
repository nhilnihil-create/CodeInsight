#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    int ans = n * 2;
    int same = 0;
    rep(i, n) {
        int now = 0;
        for (int j = 0; j < n; j++) {
            if (s[j + i] == t[j])
                now++;
            else
                break;
        }
        same = max(same, now);
    }

    cout << ans - same << endl;
    return 0;
}
