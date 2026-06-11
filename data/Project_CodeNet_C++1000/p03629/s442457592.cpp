#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long lint;
typedef vector<int>vi;
typedef pair<int,int>pii;
#define rep(i,n)for(int i=0;i<(int)(n);++i)

int dp[26][222222];
pair<int,char> tap[222222];

int main(){
  string a;
  cin>>a;
  int n=a.size();
  rep(i,26)dp[i][n]=n;
  for(int i=n-1;i>=0;--i){
    rep(j,26)dp[j][i]=dp[j][i+1];
    dp[a[i]-'a'][i]=i;
  }
  tap[n]=make_pair(1,'a');
  for(int i=n-1;i>=0;--i){
    pair<int,char> m(n+1,'+');
    rep(j,26){
      int nxt=dp[j][i]+1;
      char ch='a'+j;
      if(nxt>n)m=min(m,make_pair(1,ch));
      else m=min(m,make_pair(tap[nxt].first+1,ch));
    }
    tap[i]=m;
  }
  string ans;
  int rem=tap[0].first;
  int cur=0;
  while(rem>0){
    char ch=tap[cur].second;
    ans+=ch;
    cur=dp[ch-'a'][cur]+1;
    rem--;
  }
  cout<<ans<<endl;
}
