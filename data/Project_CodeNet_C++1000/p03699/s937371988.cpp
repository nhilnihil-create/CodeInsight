#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0, mn = 105;
    rep(i, n) {
        int s;
        cin >> s;
        if (s % 10 == 0)
            ans1 += s;

        else {
            ans2 += s;
            mn = min(mn, s);
        }
    }
    if (ans2 == 0) {
        cout << 0 << endl;
    } else if (ans2 % 10 == 0)
        cout << ans1 + ans2 - mn << endl;
    else
        cout << ans1 + ans2 << endl;
}
