#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  string s;
  cin>>s;
  int n=s.size();

  ll dp[n+1],next[n+1][27];

  for(int i=0;i<=n;i++){
    dp[i]=1e8;
    for(int j=0;j<=26;j++){
      next[i][j]=n;
    }
  }

  for(int i=n-1;i>=0;i--){
    for(int j=0;j<26;j++){
      next[i][j]=next[i+1][j];
      next[i][s[i]-'a']=i;
    }
  }

  dp[n]=1;
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<26;j++){
      if(next[i][j]==n) dp[i]=1ll;
      else dp[i]=min(dp[i],dp[next[i][j]+1]+1);
    }
  }

  string ans="";
  int it=0;
  while(ans.size()<dp[0]){
    for(int j=0;j<26;j++){
      if(next[it][j]==n){
        ans=ans+(char)('a'+j);
        break;
      }
      if(dp[it]==dp[next[it][j]+1]+1){
        ans=ans+(char)('a'+j);
        it=next[it][j]+1;
        break;
      }
    }
  }

  cout<<ans<<endl;

  return 0;
}
