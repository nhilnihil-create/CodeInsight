#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    vector<bool> f(1e9+100);
    rep(i,n){
        cin >> a[i];
        f[a[i]] = i % 2;
    }
    sort(all(a));

    ll ans = 0;
    rep(i,n){
        if(f[a[i]] && i % 2 == 0)ans++;
    }
    cout << ans << endl;
    return 0;
}