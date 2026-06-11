#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(ll i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    ll N;
    cin >> N;
    //dp[i]:=i項を決める方法
    ll dp[N+1], sum[N+1];
    dp[0] = 1, dp[1] = N;
    sum[0] = 1, sum[1] = N+1;
    rep2(i, 2, N){
        dp[i] = sum[i-1]+MOD-dp[i-2]+(N-i+1)+(N-1)*(N-1);
        dp[i] %= MOD;
        sum[i] = (sum[i-1]+dp[i])%MOD;
    }
    cout << dp[N] << endl;
}