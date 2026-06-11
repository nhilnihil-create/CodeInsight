#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 400;
int n, ma, mb, a, b, c;
int dp[N + 1][N + 1];

int main() {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    cin >> n >> ma >> mb;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        for (int ka = N; ka >= 0; --ka) {
            for (int kb = N; kb >= 0; --kb) {
                if (ka >= a && kb >= b && dp[ka - a][kb - b] != 0x3f3f3f3f) {
                    dp[ka][kb] = min(dp[ka][kb], dp[ka - a][kb - b] + c);
                    int g = __gcd(ka, kb);
                    if (ka / g == ma && kb / g == mb) {
                        ans = min(ans, dp[ka][kb]);
                    }
                }
            }
        }
    }
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
    return 0;
}
