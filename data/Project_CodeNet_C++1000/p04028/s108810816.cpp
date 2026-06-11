#include <bits/stdc++.h>
const int MOD=1000*1000*1000+7,N=5005;
using namespace std;
typedef long long ll;
ll dp[N][N],n;
string s;
ll P(ll a,ll b){
    ll ans=1;
    while(b){
        if(b%2)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ans;
}
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n;
    cin>>s;
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int p=0;p<=i;p++){
            dp[i+1][p+1]=(dp[i+1][p+1]+2*dp[i][p])%MOD;
            if(p!=0)dp[i+1][p-1]=(dp[i+1][p-1]+dp[i][p])%MOD;
            else dp[i+1][0]=(dp[i+1][0]+dp[i][0])%MOD;

            //cout<<i<<' '<<p<<' '<<dp[i][p]<<endl;
        }
    }

    int sz=s.size();
    ll v=dp[n][sz];
    for(int i=1;i<=sz;i++)v=(v*P(2,MOD-2))%MOD;
    cout<<v<<'\n';
    return 0;
}
