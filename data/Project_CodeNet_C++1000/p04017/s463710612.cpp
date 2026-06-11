#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e5 + 5, L = 20;
int a[N], b[N][L];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m >> q;

    for (int i = n - 1; i >= 0; i--) {
        b[i][0] = upper_bound(a, a + n, a[i] + m) - a - 1;
        for (int j = 1; j < L; j++) {
            b[i][j] = b[b[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y)
            swap(x, y);

        int ans = 0;
        for (int j = L - 1; j >= 0; j--) {
            if (b[x][j] < y) {
                ans += (1 << j);
                x = b[x][j];
            }
        }

        ans++;

        cout << ans << "\n";
    }

    return 0;
}