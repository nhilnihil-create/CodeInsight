#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>>cnt(n);
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        cnt[i]=make_pair(a,b);
    }
    sort(cnt.begin(),cnt.end());
    ll count=0;
    ll ans;
    for(ll i=0;i<n;i++){
        count += cnt[i].second;
        if(count>=k){
            ans=cnt[i].first;
            break;
        }
    }
    cout << ans << endl;
}