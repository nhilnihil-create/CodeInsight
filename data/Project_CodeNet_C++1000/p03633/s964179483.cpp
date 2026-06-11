#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    ll N; cin>>N;
    ll ans = 1;
    rep(i, N){
        ll T; cin>>T;
        ans = ans/__gcd(ans, T)*T;
    }

    cout << ans << endl;
}
