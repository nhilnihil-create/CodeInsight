#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    cin>>N;
    ll ans = 1, temp = 0;
    vec dp(N), sum(N);
    rep(i,N){
        if(i < 3){
            dp[i] = 1;
            sum[i] = i + 1;
        }else{
            (temp += sum[i-3])%=MOD;
            dp[i] = (1 + temp)%MOD;
            sum[i] = (sum[i-1] + dp[i])%MOD;
        }
        (ans += dp[i] * ((i == N - 1 ? 1 : N) * (N - 1) % MOD))%=MOD;
        //cout<<i<<' '<<ans<<endl;
    }
    /*rep(i,N) cout<<dp[i]<<' ';
    cout<<endl;*/
    //(ans += ((MOD + sum[N-1] * 2 - dp[N - 1])%MOD) * (N - 1))%=MOD;
    cout<<ans<<endl;
}