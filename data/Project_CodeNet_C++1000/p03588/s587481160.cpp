#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>>data(n);
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        data[i]={a,b};
    }
    sort(data.begin(),data.end());
    ll ans=data[n-1].first+data[n-1].second;
    cout << ans << endl;
}