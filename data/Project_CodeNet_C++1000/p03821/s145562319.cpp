#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n),b(n);
    for(ll i=0;i<n;i++) cin >> a[i] >> b[i];
    ll ans=0;
    for(ll i=n-1;i>=0;i--){
        a[i]+=ans;
        ll dx=b[i]-a[i];
        if(a[i]==0) continue;
        if(dx>=0){
            ans+=dx;
        }else{
            dx*=-1;
            if(dx%b[i]==0) continue;
            ll cn=dx/b[i];
            b[i]*=cn+2;
            ans+=b[i]-a[i];
        }
    }
    cout << ans << endl;
}