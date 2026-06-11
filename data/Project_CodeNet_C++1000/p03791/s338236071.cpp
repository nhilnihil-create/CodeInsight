#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005
const int MOD = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll x[n];
    rep(i,n)cin >> x[i];

    ll dp[n] = {};
    ll now = 0;

    rep(i,n){
        if(i == 0){
            x[i] = 1;
            dp[i] = now;
        }else{
            dp[i] = now;
            if(x[i] < (i - now) * 2 + 1){
                now++;
            }
        }
    }


    ll ans = 1;

    rep(i,n){
        ans *= n - dp[i] - (n - 1 - i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
 
 
