#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[a[i]] == i) {
            ans++;
            a[a[i]] = 0;
        }
    }
    cout << ans << endl;
}