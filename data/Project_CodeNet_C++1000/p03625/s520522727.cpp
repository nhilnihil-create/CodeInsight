#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll x=0,y=0;
    ll judge=0;
    for(ll i=0;i<n;i++){
        if(a[i]==a[i+1]&&judge==0){
            x=a[i];
            judge++;
            i++;
            continue;
        }
        if(a[i]==a[i+1]&&judge==1){
            y=a[i];
            judge++;
        }
    }
    ll ans=x*y;
    cout << ans << endl;
}