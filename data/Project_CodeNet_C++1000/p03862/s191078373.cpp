#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    int n,x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll ans = 0;

    rep(i,n-1){
        if(a[i]>x){
            ans += a[i]-x;
            a[i] = x;
        }
        ll sum = a[i]+a[i+1];
        if(sum>x){
            ll d = sum - x;
            ans += d;
            a[i+1] -= d;
        }
    }

    cout << ans << endl;
}