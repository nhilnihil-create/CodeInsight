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
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 0, m + 1) {
        rep(j, 0, n + 1) {
            int sum = (n - j) * i + (m - i) * j;
            if (sum == k) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}