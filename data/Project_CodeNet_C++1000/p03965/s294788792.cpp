#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll INF=1LL << 60;
int main(){
    string s;
    cin >> s;
    int n=s.size();
    vector<vector<ll>> dp(2,vector<ll> (n,-INF));
    if (s[0]=='g') dp[0][0]=0;
    else dp[0][0] = -1;
    for (int i=1;i < n;i++){
      if (i==1){
        if (s[i]== 'g'){
          dp[0][1] = dp[0][0];
          dp[1][1] = dp[0][0]+1LL;
         }
        else{
          dp[0][1] = dp[0][0]-1LL;
          dp[1][1] = dp[0][0];
        }
      }
      else {
        if (s[i]== 'g'){
          dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
          dp[1][i] = dp[0][i-1]+1LL;
         }
        else{
          dp[0][i] = max(dp[0][i-1]-1LL,dp[1][i-1]-1LL);
          dp[1][i] = dp[0][i-1];
        }  
      }
    }
    //rep(i,n){
    //  cout << dp[0][i] << " "; 
    //}
    //printf("\n");
    //rep(i,n){
    //  cout << dp[1][i] << " ";
    //}
    //printf("\n");
    cout << max(dp[0][n-1],dp[1][n-1]) << endl;
    
    return 0;
}
