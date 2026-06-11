#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> v;
    for(ll i = 0; i < n; ++i){
        ll tmp; cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0, f = 0;
    for(ll i = 0; i < n - 1; ++i){
        if(f && v[i] == v[i + 1]){
            cout << ans * v[i];
            return 0;
        }
        else if(v[i] == v[i + 1] && !f)ans = v[i], f = 1, i += 1;

    }
    cout << 0;
    return 0;
}
