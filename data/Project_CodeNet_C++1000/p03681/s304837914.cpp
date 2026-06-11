#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int n,m;
    cin >> n >> m;
    if(abs(n- m ) > 1){
        cout << 0 << endl;
    }else{
        ll ans = 1;
        repi(i,n + 1,1){
            ans *= i;
            ans %= MOD;
        }
        repi(i,m + 1,1){
            ans *= i;
            ans %= MOD;
        }
        if(n == m)ans *= 2;
        cout << ans % MOD << endl;
    }
    return 0;
}