        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;
    int dp[5001][5001];
     signed main(){
         int n;string s;
         cin>>n>>s;
      fill(dp[0],dp[0]+n+1,0);
        dp[0][0]=1;
        for(int i=1;i<=n;i++)for(int j=0;j<=n;j++){
            dp[i][j]=0;
            if(j>0)dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=dp[i-1][j];
            if(j<n)dp[i][j]=(dp[i][j]+dp[i-1][j+1]*2)%MOD;
        }
        cout<<dp[n][s.size()]<<endl;
        return 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cerr<<dp[i][j]<<' ';
            }
            cerr<<endl;
        }
     }


 


 






    





      

        
