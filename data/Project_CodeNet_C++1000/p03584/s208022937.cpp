#include <iostream>
using namespace std;
typedef long long ll;
ll n, k, bit[40], a[100100], b[100100], maxbit, ans;

ll pow(ll x, ll y){
    if (y == 0) return 1;
    if (y % 2){
        return x * pow(x, y - 1);
    } else {
        ll yyy = pow(x, y / 2);
        return yyy * yyy;
    }
}

int main(void){
    // Your code here!
    cin >> n >> k;
    for (ll i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (ll i = 0; i < 39; i++){
        bit[i] = k % 2;
        k /= 2;
        if (bit[i] == 1) maxbit = i;
    }
    for (ll i = 0; i <= maxbit + 1; i++){
        if (i != 0 && bit[i - 1] == 0) continue;
        ll whole = 0, sum = 0;
        if (i != 0) whole += pow(2, i - 1) - 1;
        for (ll j = i; j <= maxbit; j++){
            whole += bit[j] * pow(2, j);
        }
        for (ll j = 0; j < n; j++){
            if (whole == (whole | a[j])) sum += b[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
