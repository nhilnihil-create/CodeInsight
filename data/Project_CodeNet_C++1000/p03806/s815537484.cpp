#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,ma,mb;
    cin>>n>>ma>>mb;
    int a[n],b[n],c[n];
    int dp[n+1][401][401];
    for(int i=0;i<=n;i++)for(int j=0;j<=400;j++)for(int k=0;k<=400;k++)dp[i][j][k]=1e9;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                if(dp[i][j][k]==1e9)continue;
                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
                dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
            }
        }
    }
    int ans=1e9;
    for(int i=1;i<=400;i++){
        for(int j=1;j<=400;j++){
            //cout << dp[n][i][j]<<" ";
            if(i*mb==j*ma)ans=min(ans,dp[n][i][j]);
        }
        //cout <<endl;
    }
    if(ans==1e9)ans=-1;
    cout<< ans<<endl;
    return 0;
}