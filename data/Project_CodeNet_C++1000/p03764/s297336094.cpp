#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> x(n),y(m),xl(n-1),yl(m-1);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<m;i++) cin >> y[i];

    for(int i=0;i<n-1;i++) xl[i] = x[i+1]-x[i];
    for(int i=0;i<m-1;i++) yl[i] = y[i+1]-y[i];
    
    ll x_sum=0,y_sum=0;
    for(int i=0;i<n-1;i++){
        x_sum = ( x_sum + ((xl[i] * (i+1))%MOD * (n-1-i))%MOD)%MOD;
    }
    for(int i=0;i<m-1;i++){
        y_sum = ( y_sum + ((yl[i] * (i+1))%MOD * (m-1-i))%MOD)%MOD;
    }
    ll ans = (x_sum*y_sum)%MOD;
    cout << ans << endl;
    return 0;
}