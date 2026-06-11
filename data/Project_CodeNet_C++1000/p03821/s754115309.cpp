#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i] >> b[i];
    }

    ll ans = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (ll i = 0; i < n; i++){
        a[i] += ans;
        if (a[i]%b[i] != 0){
            ans += b[i] - (a[i]%b[i]);
        }
    }

    cout << ans << "\n";
}