#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


ll factorial(ll n) {
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        ans *= i;
    }
    return ans;
}

int main() {
    int n, p; cin >> n >> p;
    int od = 0, ev = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a & 1) od++;
        else ev++;
    }

    if(od == 0){
        ll ans = pow(2, n);
        if(p == 0) cout << ans<< endl;
        else cout << 0 << endl;
    }else{
        ll ans = pow(2, n - 1);
        cout << ans << endl;
    }

    return 0;
}
