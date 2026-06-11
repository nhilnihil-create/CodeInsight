#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, 2, n + 1) {
        int now = i;
        for (int j = 2; j * j <= now; j++) {
            while (now % j == 0) {
                now /= j;
                mp[j]++;
            }
        }
        mp[now]++;
    }
    int ans = 1;
    const int mod = 1e9 + 7;
    for (auto p : mp) {
        if (p.first == 1) continue;
        ans = ans * (p.second + 1) % mod;
    }
    cout << ans << "\n";
}