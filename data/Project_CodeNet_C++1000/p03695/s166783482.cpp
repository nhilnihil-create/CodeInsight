#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<bool> vis(8, 0);
    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] / 400 > 7) {
            mx++;
            continue;
        }
        vis[a[i] / 400] = true;
        mn = 0;
        for (int j = 0; j < 8; j++) {
            mn += vis[j];
        }
        mx = mn;
    }
    if (mn == 0 && mx) mn = 1;
    cout << mn << ' ' << mx << '\n';
    return 0;
}

