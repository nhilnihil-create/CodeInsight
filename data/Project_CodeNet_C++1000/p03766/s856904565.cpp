#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 2000005
ll dp[MAX_N] = {};
ll sum[MAX_N] = {};
int main() {
    ll n;
    cin >> n;
    ll MOD = 1000000007;
 

    drep(i,n+1){
        if(i==0)break;
        if(i==n){
            dp[i] = n;
        }else if(i>=n-10){
            dp[i] = (n-1)*(n-1) + dp[i+1];
            dp[i] %= MOD;
            srep(j,2,n+1){
                if(i+j+1<=n) dp[i] += dp[i+j+1];
                else dp[i] += 1;
            }
        } else{
            dp[i] = (n-1)*(n-1) + dp[i+1];
            dp[i] %= MOD;
            dp[i] += sum[i+3];
            dp[i] += i+1;
        }
        
        dp[i] %= MOD;
        sum[i] = dp[i];
        if(i<n)sum[i] += sum[i+1];
        sum[i]%=MOD;
    }

    cout << dp[1] << endl;
    return 0;
}


