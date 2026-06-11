#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

string S;
int N;

int nxt[200020][26];
int dp[200020];

int main(){
  cin>>S;
  N=S.size();

  for(int i=0;i<=N;i++) for(int j=0;j<26;j++) nxt[i][j]=N;

  for(int i=N-1;i>=0;i--){
      for(int k=0;k<26;k++){
          nxt[i][k]=nxt[i+1][k];
      }
      nxt[i][S[i]-'a']=i;
  }

  for(int i=0;i<=N;i++) dp[i]=N;
  dp[N]=0;
  for(int i=N-1;i>=0;i--){
      for(int k=0;k<26;k++){
          dp[i]=min(dp[i],dp[nxt[i+1][k]]+1);
      }
  }

  string ans="";
  int now=0;
  while(now<N){
      int mi=N;
      for(int k=0;k<26;k++) mi=min(mi,dp[nxt[now][k]]);

      for(int k=0;k<26;k++){
          if(dp[nxt[now][k]]==mi){
              ans+=string(1,char('a'+k));
              now=nxt[now][k]+1;
              break;
          }
      }
  }
  cout<<ans<<endl;



  return 0;
}
