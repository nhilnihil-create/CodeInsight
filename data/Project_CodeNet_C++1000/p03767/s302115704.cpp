#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
ll n;
cin >> n;
ll a[3*n];
for (ll i = 0; i < 3 * n; i++) cin >> a[i];
sort(a, a + 3 * n, greater<ll>());
ll ans = 0;
for (ll i = 0; i < n;i++){
    ans += a[2 * i + 1];
}
cout << ans << endl;
}
