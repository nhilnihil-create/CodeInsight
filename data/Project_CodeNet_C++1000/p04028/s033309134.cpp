#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
#define N 5010
ll dp[N][N];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n; string s;
    cin>>n>>s;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<n;i++)for(int j=0;j<N-1;j++){
	mad(dp[i+1][max(0,j-1)],dp[i][j]);
	mad(dp[i+1][j+1],dp[i][j]*2);
    }
    ll ans=dp[n][s.size()];
    for(int i=0;i<s.size();i++){
	ans=ans*500000004%mod;
    }
    cout<<ans<<endl;
}


