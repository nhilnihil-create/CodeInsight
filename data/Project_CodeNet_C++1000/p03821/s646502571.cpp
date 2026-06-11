#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll ans=0;
    int n; cin >> n;
    vector<ll> a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    if(a[0]%b[0]!=0) ans += b[0]-a[0]%b[0];
    for(int i = 1; i < n; i++) {
        a[i]+= ans;
        if(a[i]%b[i]==0) continue;
        ll x=b[i]-a[i]%b[i];
        ans += x;
    }

    cout << ans << endl;
    return 0;
}