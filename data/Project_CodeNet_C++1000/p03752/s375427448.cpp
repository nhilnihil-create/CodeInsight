#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
 
const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;

    ll a[n];
    rep(i, n)cin >> a[i];

    ll ans = LINF;

    rep(bit, (1<<n)){
        ll cnt     = 0;
        ll score   = 0;
        ll highest = a[0]-1;

        rep(i, n){
            if(bit & (1<<i)){
                score += max((ll)0, highest-a[i]+1);
                highest = max(highest+1, a[i]);
                cnt++;
            }
            highest = max(highest, a[i]);
        }

        if(cnt >= k){
            ans = min(ans, score);
        }
    }

    cout << ans << endl;
}