#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int id[200009][26],n,dp[200009],idx;
string s,ans;

void build_table(){
  int cnt[26];
  r(i,26)cnt[i]=n+1;
  for(int i=n-1;i>=0;i--){
    r(j,26)id[i][j]=cnt[j];
    cnt[s[i]-'a']=i;
  }
}

void solve(){
  for(int i=n-1;i>=0;i--){
    int p=0;
    r(j,26)p=max(p,id[i][j]);
    dp[i]=dp[p]+1;
  }
  while(idx<n){
    r(i,26){
      if(dp[id[idx][i]]+1==dp[idx]){
        idx=id[idx][i];
        ans+=('a'+i);
        break;
      }
    }
  }
  cout<<ans<<endl;
}

signed main(){
  cin>>s;
  s='@'+s;
  n=s.size();
  build_table();
  solve();
}