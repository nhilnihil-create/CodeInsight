#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab;
    for(ll i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }
    sort(ab.begin(), ab.end());
    
    ll ans = 0;
    /*for(int i=0; i<n; i++){
        if(k > ab[i].second){
            k -= ab[i].second;
        }else if(k <= ab[i].second){
            ans = ab[i].first;
            break;
        }
    }*/
    ll tmp = 0;
    for(ll i=0; i<n; i++){
        tmp += ab[i].second;
        if(tmp >= k){
            cout << ab[i].first << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;

}