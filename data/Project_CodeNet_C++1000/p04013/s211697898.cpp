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

const int N = 52;
int n, a;
ll ans;
int num[N];
ll dp[N][N * N];

void init() {
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            for (int k = 2500; k >= 0; --k) {
                if (dp[j][k] != 0 && k + num[i] <= 2500) {
                    dp[j + 1][k + num[i]] += dp[j][k];
                }
            }
        }
    }
}


int main() {
    cin >> n >> a;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    init();
    for (int i = 1; i <= n; ++i) {
        if (i * a <= 2500)
            ans += dp[i][i * a];
    }
    cout << ans << endl;

    return 0;
}
