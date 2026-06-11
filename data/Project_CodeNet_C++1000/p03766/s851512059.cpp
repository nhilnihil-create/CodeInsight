        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;
//

int n,ans2[1000];
 int dp[2][1000000],dp2[2][1000001];
int d[1000];
void dfs(int a){
  if(a==n){
    int t=n;
    while(t>0&&d[t-1]!=1)t--;
    ans2[t]++;
    for(int i=0;i<n;i++)for(int j=i+1;j<i+d[i];j++)if(d[min(n-1,j)]!=d[min(n-1,j+1)]){
      ans2[t]--;
      return;
    }
   
    return ;
  }
  for(int i=1;i<=n;i++){
    d[a]=i;
    dfs(a+1);
  
  }
  return ;
}
     signed main(){
 int ans=0;
 cin>>n;
//for(int i=0;i<=n;i++)ans2[i]=0;
 dp[0][0]=n-1;dp[1][0]=0;
 for(int i=1;i<=n;i++){
   dp[0][i]=(dp[0][i-1]+dp[1][max(i-3,0ll)])%MOD;
 
   dp[1][i]=(dp[1][i-1]+dp[0][i])%MOD;
 }
  dp2[0][0]=0;dp2[1][0]=1;
 for(int i=1;i<n;i++){
  if(i>=3) dp2[0][i]=(dp2[0][i-1]+dp2[1][i-3])%MOD;
 else dp2[0][i]=0;
   dp2[1][i]=(dp2[1][i-1]+dp2[0][i])%MOD;
 }
 ans=(dp[1][n-1]+1+dp2[1][n-1]*(n-1)%MOD+(n-1)*(n-1)%MOD)%MOD;
 for(int i=2;i<n;i++)ans=(ans+dp2[1][n-i]*(n-1)%MOD*(n-1)%MOD)%MOD;
cout<<ans<<endl;
//for(int i=0;i<n;i++)cerr<<dp[0][i]<<' '<<dp[1][i]<<endl;
//for(int i=0;i<=n;i++)cerr<<dp2[0][i]<<' '<<dp2[1][i]<<endl;
//a!=n-1nobaai
//dfs(0);
//for(int i=n;i>=0;i--)cerr<<ans2[i]<<' ';
//cerr<<endl;
//cerr<<dp[1][n-1]+1<<' '<<dp2[1][n-1]*(n-1)%MOD<<' ';
//for(int i=2;i<n;i++)cerr<<dp2[1][n-i]*(n-1)%MOD*(n-1)%MOD<<' ';
//cerr<<(n-1)*(n-1)%MOD<<endl;

     }


 


 






    





      

        
