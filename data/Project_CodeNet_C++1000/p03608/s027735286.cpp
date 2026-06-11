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

const int N = 8;
int n, m, r, a, b, c, ans;
int R[N];
int e[210][210];

int main() {
    ans = 1e9;
    memset(e, 0x3f, sizeof e);
    cin >> n >> m >> r;
    for (int i = 0; i < r; ++i) {
        cin >> R[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        e[a][b] = c;
        e[b][a] = c;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                e[j][k] = min(e[j][k], e[j][i] + e[i][k]);
            }
        }
    }
    sort(R, R + r);
    do {
        int sum = 0;
        for (int i = 0; i < r - 1; ++i) {
            sum += e[R[i]][R[i + 1]];
        }
        ans = min(ans, sum);
    } while (next_permutation(R, R + r));
    cout << ans << endl;
    return 0;
}
