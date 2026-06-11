#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long cur = 0, ans = 0;

    while (n--) {
        int x;
        cin >> x;
        cur += x;
        if (!x || !n)
            ans += cur / 2, cur = 0;
    }
    cout << ans << '\n';
}