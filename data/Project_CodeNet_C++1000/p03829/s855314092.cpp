#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    ll n, a, b; cin >> n >> a >> b;
    V<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    V<ll> x2(n);
    for(int i = 1; i < n; i++){
        x2[i - 1] = abs(x[i] - x[i - 1]);
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(x2[i] * a < b) ans += x2[i] * a;
        else ans += b;
    }
    cout << ans << endl;

}
