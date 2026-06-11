#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int n, t, ans;

void solve() {
    scanf("%d %d", &n, &t);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    int mn = 1e9;
    int x = 0;

    for (int i = 1; i <= n; ++i) {
        x = max(x, arr[i] - mn);
        mn = min(mn, arr[i]);
    }

    mn = 1e9;

    for (int i = 1; i <= n; ++i) {
        if (arr[i] - mn == x) {
            ++ans;
        }

        mn = min(mn, arr[i]);
    }

    printf("%d\n", ans);
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}