#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    ll c = 1;
    for (ll i = 1; i < n; i++){
        if (a[i-1] == a[i]){
            c++;
        }
        else{
            if (c%2 == 1){
                ans++;
            }
            c = 1;
        }
    }
    if (c%2 == 1){
        ans++;
    }

    cout << ans << endl;
}