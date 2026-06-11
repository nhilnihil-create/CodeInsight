#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n, 1);
    vector<bool> flag(n);
    flag[0] = true;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (flag[a])
            flag[b] = true;
        if (cnt[a] == 1)
            flag[a] = false;

        cnt[a]--;
        cnt[b]++;
    }

    int ans = 0;
    rep(i, n) {
        if (cnt[i] >= 1 && flag[i])
            ++ans;
    }
    cout << ans << endl;

    return 0;
}