#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int e = 0, o = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cnt++;
        } else {
            if (cnt % 2 == 0) e++;
            else o++;
            cnt = 1;
        }
    }
    if (cnt % 2 == 0) e++;
    else o++;
    int ans = e + o;
    if (e % 2 == 1) ans--;
    cout << ans << endl;
    return 0;
}