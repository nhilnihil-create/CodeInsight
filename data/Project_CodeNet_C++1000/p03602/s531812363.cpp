#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 120000000

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

int main() {
    int n;
    cin >> n;
    vector<vector<LL>> g(n, vector<LL>(n));
    vector<vector<LL>> cnt(n, vector<LL>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == k || j == k) continue;
                if (g[i][j] > g[i][k] + g[k][j]) {
                    cout << -1 << endl;
                    return 0;
                } else if (g[i][j] == g[i][k] + g[k][j]) cnt[i][j]++;
            }
        }
    }

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cnt[i][j] == 0) ans += g[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}
