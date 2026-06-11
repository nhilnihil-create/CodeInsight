#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//    idx len sum
ll dp[55][55][2505];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,a;cin>>n>>a;
    ll x[n+1];for(ll i=1;i<=n;i++)cin>>x[i];
    for(ll idx=0;idx<=n;idx++)dp[idx][0][0]=1;
    for(ll idx=1;idx<=n;idx++){
        for(ll len=1;len<=idx;len++){
            for(ll sum=0;sum<=2500;sum++){
                dp[idx][len][sum]=dp[idx-1][len][sum];
                if(sum-x[idx]>=0)
                    dp[idx][len][sum]+=dp[idx-1][len-1][sum-x[idx]];
            }
        }
    }

    ll ans = 0;
    for(ll len=1;len<=n;len++){
        ll req = a*len;
        ans+=dp[n][len][req];
        //cout<<len<<" "<<req<<"  "<<dp[n][len][req]<<endl;
    }

    cout<<ans;
}


