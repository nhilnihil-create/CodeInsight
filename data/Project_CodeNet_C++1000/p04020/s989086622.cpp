#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;
const ll MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n - 1; i ++ ) {
        ans += a[i]/2;
        if (a[i]%2 == 1 && a[i + 1] > 0) {
            ans ++;
            a[i + 1] --;
        }
    }
    ans += a[n - 1]/2;
    cout << ans << endl;
}