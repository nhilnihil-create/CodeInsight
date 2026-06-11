#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n) scanf("%d", &a[i]);

    map<int, int> cnt;
    rep(i, n) {
        cnt[a[i]]++;
        cnt[a[i] + 1]++;
        cnt[a[i] - 1]++;
    }

    int ans = 0;
    for (auto x : cnt) {
        ans = max(ans, x.second);
    }
    cout << ans << endl;
    return 0;
}