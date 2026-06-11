#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n; cin >> n;
    V<ll> a(n * 3);
    for(int i = 0; i < n * 3; i++) cin >> a[i];

    sort(ALL(a));

    // 1 2 3 4 5 5 7 8 9
    ll ans = 0;
    for(int i = 0; i < 2 * n; i+=2){
        ans += a[3 * n - 2 - i];
    }
    cout << ans << endl;

    return 0;
}
