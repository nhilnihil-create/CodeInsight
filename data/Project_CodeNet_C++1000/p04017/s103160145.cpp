#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, l, q, a[100005] = {}, h[18][100005] = {}, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> l >> q;
    for (int i = 1; i <= n; i++) h[0][i] = (int)(upper_bound(a, a + n + 1, a[i] + l) - a) - 1;
    for (int i = 1; i <= 17; i++) for (int j = 1; j <= n; j++) h[i][j] = h[i - 1][h[i - 1][j]];
    while (q--) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        int z = 0;
        while (h[0][x] < y) {
            for (int i = 1; i <= 17; i++) if (h[i][x] >= y) {z += (1 << (i - 1)); x = h[i - 1][x]; break;}
        }
        cout << z + 1 << '\n';
    }
}
