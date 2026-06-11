#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
const int N=200005;

ll modulo(ll num,ll MOD=mod){ return ((num%MOD)+MOD)%MOD;} // for negative integer
ll power(ll b,ll e,ll MOD=mod){ll ans=1; while(e){if(e%2) ans=(ans*b)%MOD; b=(b*b)%MOD; e/=2;} return ans;}
ll inv(ll num,ll MOD=mod){ return power(modulo(num),MOD-2,MOD); }

ll dp[55][2600][55];

ll go(int ind, int sum, int cnt, int A, int n, int a[]) {

    if(ind==n) {
        if(sum==cnt*A) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if(dp[ind][sum][cnt]!=-1) {
        return dp[ind][sum][cnt];
    }

    ll pick=go(ind+1, sum+a[ind], cnt+1, A, n, a);
    ll dpick=go(ind+1, sum, cnt, A, n, a);

    return dp[ind][sum][cnt]=pick+dpick;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cout<<fixed<<setprecision(15);

    memset(dp,-1,sizeof(dp));
    
    int n,A;
    cin>>n>>A;
    
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    ll ans=go(0, 0, 0, A, n, a);

    cout<<ans-1;
    return 0;
}
