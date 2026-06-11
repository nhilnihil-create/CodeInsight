#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int x[m+1], y[m+1];
    for (int i = 1; i <= m; i++) cin >> x[i] >> y[i];

    int num[n+1];
    bool red[n+1];
    for (int i = 1; i <= n; i++) {
        num[i] = 1;
        red[i] = false;
    }
    red[1] = true;

    for (int i = 1; i <= m; i++) {
        if (red[x[i]]) {
            red[y[i]] = true;
        }

        num[x[i]] -= 1;
        num[y[i]] += 1;

        if (!num[x[i]]) {
            red[x[i]] = false;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (red[i]) ans++;
    }
    cout << ans << endl;
}