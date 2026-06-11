#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> table(100000, 0);
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        table[a]++;
    }
    ll ans = 0;
    for(ll i = 0; i < 100000 - 2; i++){
        ans = max(ans, table[i] + table[i+1] + table[i+2]);
    }
    cout << ans << endl;
}