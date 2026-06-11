
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=110;
ll dp[maxn][maxn*3];
ll n,s,w[maxn],v[maxn];
 
int main(){
    cin>>n>>s;
    for (int i=1; i<=n ;i++)
        cin>>w[i]>>v[i];
    w[0]=w[1]-1;
    ll sum=0;
    for (int i=1; i<=n ;i++) w[i]-=w[0],sum+=w[i];
    ll ans=0;
 
    for (int i=1; i<=n ;i++){
        for (int j=i;j >=1;j--){
            for (int k=sum;k>=w[i];k--){
                dp[j][k]=max(dp[j][k],dp[j-1][k-w[i]]+v[i]);
                if(1ll*j*w[0]+k<=s) ans=max(dp[j][k],ans);
            }
        }
    }
 
    cout<<ans<<endl;
    return 0;
}
