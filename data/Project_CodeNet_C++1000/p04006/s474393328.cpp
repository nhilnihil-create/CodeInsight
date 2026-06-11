#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    ll x;
    cin >> N >> x;
    vector<ll> a(N), b(N);
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
        ans += a[i];
    }
    
    for (ll i = 1; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < N; j++) b[j] = min(b[j], a[(j-i+N)%N]);
        for (int j = 0; j < N; j++) sum += b[j];
        ans = min(ans, sum+x*i);
    }
    cout << ans << endl;
    return 0;
}