#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll>t(n);
    for(ll i=0;i<n;i++) cin >> t[i];
    sort(t.begin(),t.end());
    ll ans=0;
    ll i=0;
    while(i<n){
        i++;
        ll cnt=1,time=0;
        while(cnt<c&&time<=k){
            if(time+t[i]-t[i-1]>k) break;
            time+=t[i]-t[i-1];
            cnt++;
            i++;
        }
        ans++;
    }
    cout << ans << endl;
}