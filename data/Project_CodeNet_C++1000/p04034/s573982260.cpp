#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, m; cin >> n >> m;
    vector<bool> red(n, false);
    vector<int> cnt(n, 1);
    red[0] = true;

    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;

        if (red[x] && cnt[x] == 1) {
            red[x] = false;
            red[y] = true;
        } else if (red[x] && cnt[x] > 1) {
            red[y] = true;
        }

        cnt[x]--;
        cnt[y]++;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (red[i]) ans++;
    }

    cout << ans << endl;
}