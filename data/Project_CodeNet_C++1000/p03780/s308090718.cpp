#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
ll n, k;
pair<ll, ll> a[5000];
bool solve(pair<ll, ll> domey, pair<ll, ll> mid){
    bool dp[k + 1] = {1};
    for(ll i = 0; i < n; i++){
        if(i == mid.second) continue;
        bool nextdp[k + 1];
        for(ll j = 0; j <= k; j++) nextdp[j] = dp[j];
        for(ll j = a[i].first; j <= k; j++) nextdp[j] |= dp[j - a[i].first];
        for(ll j = 0; j <= k; j++) dp[j] = nextdp[j];
    }
    bool ret = 0;
    for(ll i = max<ll>(0, k - mid.first); i < k; i++) ret |= dp[i];
    return ret;
}
int main(){
    cin >> n >> k;
    ll sum = 0;
    for(ll i = 0; i < n; i++) cin >> a[i].first;
    sort(a, a + n);
    for(ll i = 0; i < n; i++) a[i].second = i;
    auto po = upper_bound(a, a + n, pair<ll, ll>(0, 0), solve);
    cout << po - a << endl;
    return 0;
}