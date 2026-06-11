#include <iostream>
using namespace std;
using ll = long long int;
const ll MOD = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;

    ll ans = 0;
    ll fn = 1;
    ll fm = 1;
    if(m < n){
        int t = n;
        n = m;
        m = t;
    }
    for(ll i = 1; i <= n; i++){
        fn *= i;
        fn %= MOD;
    }
    fm = fn;
    for(ll i = n+1; i <= m; i++){
        fm *= i;
        fm %= MOD;
    }

    if(n == m){
        ans = 2;
        ans *= fm;
        ans %= MOD;
        ans *= fn;
        ans %= MOD;
    }else if(m-n == 1){
        ans = 1;
        ans *= fm;
        ans %= MOD;
        ans *= fn;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}