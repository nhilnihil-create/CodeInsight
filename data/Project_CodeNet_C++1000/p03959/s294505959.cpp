#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

int main() {
    int n; cin >> n;
    vector<ll> t(n), a(n);
    for (int i=0; i<n; ++i) {
        cin >> t[i];
    }
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    vector<bool> ft(n);
    ll cur=t[0];
    ft[0]=true;
    for (int i=1; i<n; ++i) {
        if (t[i]!=cur) {
            ft[i]=true;
            cur=t[i];
        }
    }
    vector<bool> fa(n);
    cur=a[n-1];
    fa[n-1]=true;
    for (int i=n-1; i>=0; --i) {
        if (a[i]!=cur) {
            fa[i]=true;
            cur=a[i];
        }
    }
    ll ans=1;
    for (int i=0; i<n; ++i) {
        if (fa[i] && ft[i]) {
            ans*=(a[i]==t[i]);
        } else if (fa[i]) {
            ans*=(a[i]<=t[i]);
        } else if (ft[i]) {
            ans*=(t[i]<=a[i]);
        } else {
            ans*=min(a[i], t[i]);
            ans%=MOD;
        }
    }
    cout << ans;
    return 0;
}