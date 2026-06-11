#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll>x(n);
    for(ll i=0;i<n;i++) cin >> x[i];
    ll ans=0;
    for(ll i=1;i<n;i++){
        if((x[i]-x[i-1])*a<b){
            ans+=(x[i]-x[i-1])*a;
        }else{
            ans+=b;
        }
    }
    cout << ans << endl;
}