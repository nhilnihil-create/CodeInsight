#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i =0 ; i < n; i++) {
        cin >> a[i];
    }
    a[n] = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] / 2;
        a[i] %= 2;
        if (a[i] && a[i + 1]) {
            a[i]--;
            a[i + 1]--;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
