#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

vector<vector<ll>> dp(5010,vector<ll>(5010,0));
// a^b
ll mypow(ll a, ll b) {
    if (b == 0) return 1;
    ll tmp = mypow(a, b / 2);
    if (b % 2) return (((tmp*tmp) % MOD)*a) % MOD;
    else return (tmp*tmp) % MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    string s;cin>>s;
    int len=s.length();
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j+1] += dp[i][j]*2;
            dp[i+1][j+1] %= MOD ;

            if(j!=0){
                dp[i+1][j-1] += dp[i][j];
                dp[i+1][j-1] %= MOD;
            }
            else{
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
        }
    }
    ll res=dp[n][len],tmp=mypow(2,len);
    tmp = mypow(tmp,MOD-2);
    res *= tmp; res %= MOD;
    cout<<res<<endl;
}
