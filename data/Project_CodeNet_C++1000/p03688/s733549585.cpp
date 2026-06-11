#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int mini = 1e9;
    int maxi = 0;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mini = min(a[i], mini);
        maxi = max(a[i], maxi);
    }
    if (mini == maxi) {
        if (mini == n-1) {
            cout << "Yes\n";
            exit(0);
        }
        if (mini <= n/2) cout << "Yes\n";
        else cout << "No\n";
    } else if (maxi-1 == mini) {
        int cnt = 0;
        for (int i = 0; i < n; i++) if (a[i] == mini) cnt++;
        int rem = n-cnt;
        if (rem == 1) {
            cout << "No\n";
            exit(0);
        }
        if (maxi <= cnt+rem/2 && mini >= cnt) cout << "Yes\n";
        else cout << "No\n";
    } else {
        cout << "No\n";
    }
}
/*

 */