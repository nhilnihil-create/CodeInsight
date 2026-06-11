#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,t;
    cin >> n >> t;
    vector<ll>time(n);
    for(ll i=0;i<n;i++){
        cin >> time[i];
    }
    ll ans=0;
    for(ll i=1;i<n;i++){
        if(time[i]-time[i-1]>t){
            ans+=t;
        }
        else {
            ans+=time[i]-time[i-1];
        }
    }
    ans+=t;
    cout << ans << endl;
}