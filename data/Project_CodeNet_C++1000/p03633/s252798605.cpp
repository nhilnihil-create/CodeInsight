#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;

int main(){
    int n; cin >> n;
    ll a[n] = {0}; rep(i, n) cin >> a[i];

    if(n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    ll ans = lcm(a[0], a[1]);
    loop(i, 2, n){
        ans = lcm(ans, a[i]);
    }
    cout << ans << endl;

    return 0;
}