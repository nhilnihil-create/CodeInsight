#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n, x;
    cin >> n >> x;
    ll ans = n;
    ll a = x, b = n - x;
    while (a != 0) {
        ans += 2LL * a * (b / a);
        b %= a;
        swap(a, b);
    }
    cout << ans - b << '\n';
}