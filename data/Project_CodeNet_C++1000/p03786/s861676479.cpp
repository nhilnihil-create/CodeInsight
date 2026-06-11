#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int64_t a[n];
    rep(i,n) cin >> a[i];
    sort(a, a+n);
    int64_t suma[n+1];
    suma[0] = 0;
    rep(i,n) suma[i+1] = suma[i] + a[i];
    int ans = 1;
    rep(i,n-1) {
        if (2*suma[n-i-1] >= a[n-i-1]) ans++;
        else break;
    }
    cout << ans << endl;
}