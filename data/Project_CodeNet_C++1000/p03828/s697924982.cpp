#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>num(1e3+100,1);
    for(ll i=0;i<=n;i++){
        ll number=i;
        for(ll j=2;j<=i;j++){
            while(number%j==0){
                num[j]++;
                number/=j;
            }
        }
    }
    ll ans=1;
    for(ll i=2;i<=n;i++){
        ans*=num[i];
        ans%=MOD;
    }
    cout << ans << endl;
}
