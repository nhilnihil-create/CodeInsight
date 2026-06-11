#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}
const long long MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 10 ;
long long dp[MAXN] ;
long long cdp[MAXN] ;
int main(int argc,char* argv[]) { 
    io() ;
    #ifndef ONLINE_JUDGE
      //  freopen("inp.txt", "r", stdin) ;
        // freopen("out.txt", "w", stdout);
    #endif
    long long n ;
    cin >> n ;
    dp[1] = n ;
    cdp[1] = dp[1] ;
    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1] + ((n - 1)*(n - 1))%MOD + (n - max(i-1,2) + 1) ;
        dp[i] %= MOD ;
        if(i > 3){
            dp[i] = (dp[i] + cdp[i-3])%MOD ;
        }
        cdp[i] = (cdp[i-1] + dp[i])%MOD ;
    }
    cout << dp[n] << endl ;
    return 0 ; 
}