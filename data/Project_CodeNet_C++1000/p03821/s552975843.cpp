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
    V<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    ll cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if((cnt + a[i]) % b[i] != 0){
            ll x = (cnt + a[i]) / b[i];
            ll y = (x + 1) * b[i] - (a[i] + cnt);
            cnt += y;
        }
    }
    cout << cnt << endl;

    return 0;
}
