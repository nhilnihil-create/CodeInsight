#include <iostream>
using namespace std;
using ll = long long int;
const ll MOD = 1000000007;

int main(){
    ll n;
    cin >> n;
    ll ans = 1;
    for(ll i = 2; i <= n; i++){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}