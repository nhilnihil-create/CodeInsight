// All Heil Fire Lord Zuko

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000 * 1000 + 19;

int n;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    LL ans = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        LL a;
        cin >> a;
        if (i == 0)
            ans += a - 1;
        else if (a == cnt + 1)
            cnt++;
        else if (a > cnt + 1)
            ans += (a - 1) / (cnt + 1);
    }
    cout << ans;
    return 0;
}
