#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ii> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

int main(){
    int n,ma,mb;cin>>n>>ma>>mb;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
    int dp[n+1][401][401];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
                if(j>=a[i]&&k>=b[i]){
                    dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
                }
            }
        }
    }
    int ans=INF;
  for(int i=1;i*ma<=400&&i*mb<=400;i++){
    ans=min(ans,dp[n][i*ma][i*mb]);
  }
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}