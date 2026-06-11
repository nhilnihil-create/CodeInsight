#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<bool> vis(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (a[a[i]] == i) {
            vis[i] = vis[a[i]] = true;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}