#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  string s;
  cin >> s;
  int n=s.length();
  vector<pair<int,int>> dp(n+1);
  vector<int> pos(26,-1);
  for(int i=n;i>=0;i--){
    dp[i]={IINF,-1};
    for(int j=0;j<26;j++){
      if(pos[j]==-1){
        dp[i]={1,-j};
        break;
      }
      if(dp[i].first>dp[pos[j]].first+1){
        dp[i]={dp[pos[j]].first+1,pos[j]};
      }
    }
    if(i>0) pos[s[i-1]-'a']=i;
  }
  string ans="";
  int now=0;
  while(1){
    now=dp[now].second;
    if(now<=0){
      ans+=string(1,'a'-now);
      break;
    }
    ans+=string(1,s[now-1]);
  }
  cout << ans << endl;
  return 0;
}