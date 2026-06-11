#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    
    ll ans = 0;
    rep(i,n-1){
        if(a[i] / 2 > 0){
            ans += a[i]/2;
            a[i] %= 2;
        }
        ll tmp = min(a[i], a[i+1]);
        ans += tmp;
        a[i] -= tmp;
        a[i+1] -= tmp;
    }
    ans += a[n-1]/2;
    
    cout << ans << endl;
    
    //cout << endl;
    //rep(i,n)cout << a[i] << ((i < n-1)?" ":"\n");
    
    return 0;
}