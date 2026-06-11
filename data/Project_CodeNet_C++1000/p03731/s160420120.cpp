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
    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans += min(t, osu[i + 1] - osu[i]);
    }
    cout << ans + t << endl;
}