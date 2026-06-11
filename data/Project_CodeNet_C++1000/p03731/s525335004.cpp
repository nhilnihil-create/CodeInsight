#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, t;
    cin >> n >> t;
    vector<ll> osu(n);
    for(int i = 0; i < n; i++){
        cin >> osu[i];
    }
    ll ans = t;
    for(int i = 1; i < n; i++){
        ll x = 0;
        if(osu[i] - osu[i - 1] < t) x = t - (osu[i] - osu[i - 1]);
        ans += t - x;
    }
    cout << ans << endl;
}