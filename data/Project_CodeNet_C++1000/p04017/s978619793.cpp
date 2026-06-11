#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)    

const int N = 100005;

int nx[20][N];
int a[N];
int n, l, q;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 1e9 + 1;
    cin >> l;
    for (int i = 1; i <= n; i++) {
        nx[0][i] = upper_bound(a + 1, a + n + 2, a[i] + l) - a - 1;
    }
    nx[0][n + 1] = n + 1;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n + 1; j++) {
            nx[i][j] = nx[i - 1][nx[i - 1][j]];
        } 
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        int ans = 0;
        for (int i = 19; i >= 0; i--) {
            if (nx[i][l] < r) {
                // cout << l << ' ' << ' ' << r << ' ' << i << endl;
                l = nx[i][l];
                ans += (1 << i);
            } 
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}