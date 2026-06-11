#include <iostream>
#include <vector>
#define ll long long 
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vvvl vector<vector<vector<ll> > >
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
int main(void){
    ll a,n; cin>>n>>a;
    vl x(n);
    for(int i=0;i<n;++i) cin>>x[i];
    vvvl dp(n,vvl(n+1,vl(50*n+1,0)));
    
    for(int i=0;i<n;++i) for(int j=1;j<n+1;++j){
        //cout<<i<<" "<<j<<endl;
        if(i+1 == j){
            ll sum = 0;
            rep(k,i+1) sum += x[k];
            dp[i][j][sum] = 1;
            break;
        } rep(k,50*n+1){
            if(k-x[i] >= 0) dp[i][j][k] = dp[i-1][j][k]+dp[i-1][j-1][k-x[i]];
            else dp[i][j][k] = dp[i-1][j][k];
            if(j == 1 && x[i] == k) dp[i][j][k] += 1;
        }
    }
    ll ans = 0;
    rep(i,n+1) ans += dp[n-1][i][a*i];
    cout<<ans<<endl;
}
