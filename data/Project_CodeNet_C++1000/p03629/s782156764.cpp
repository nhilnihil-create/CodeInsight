#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> next(n+1, vector<int>(26,n));	//i文字目以降の最初に文字cが登場するindex
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<26; j++){ next[i][j] = next[i+1][j]; }
    next[i][s[i]-'a'] = i;
  }
  
  vector<int> dp(n+1, inf);
  vector<pair<char,int>> recon(n+1,{'?',n});
  dp[n]=1;
  
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<26; j++){
      if(next[i][j]==n){
        if(dp[i]>1){ dp[i]=1; recon[i]={'a'+j,n};}	//次の文字がない時
      } else if(dp[i]>dp[next[i][j]+1]+1){
        dp[i] = dp[next[i][j]+1]+1;
        recon[i] = {'a'+j, next[i][j]+1};
      }
    }
  }
  
  string ans="";
  int index=0;
  while(index<n){
    auto p = recon[index];
    ans += p.F;
    index = p.S;
  }
  cout << ans << endl;
  return 0;
}

/*
https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
長さ nn の文字列 SS が与えられる。
SS の部分文字列 (空文字含む) として考えられるものの個数を数え上げよ。
ただし答えがとても大きくなることがあるので、個数を 1,000,000,007 で割ったあまりを求めよ。
SS = "abcde" のとき、32 通り (全文字が異なるので 25=3225=32 通り)
SS = "aaaaa" のとき、6 通り ("", "a", "aa", "aaa", "aaaa", "aaaaa")
SS = "aba" のとき、7 通り ("", "a", "b", "aa", "ab", "ba", "aba")

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> next(n+1, vector<int>(26,n));	//i文字目以降の最初に文字cが登場するindex
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<26; j++){ next[i][j] = next[i+1][j]; }
    next[i][s[i]-'a'] = i;
  }
  
  vector<ll> dp(n+1,0);
  dp[0]=1;	//reset 空文字列""にあたる
  for(int i=0; i<n; i++){
    for (int j=0; j<26; j++){
      if (next[i][j] >= n) continue; // 次の文字 j がもうない場合はスルー
      dp[next[i][j] + 1] += dp[i];
      dp[next[i][j] + 1] %= mod;
    } 
  }
  ll ans=0;
  for(int i=0; i<=n; i++){
    ans += dp[i];
    ans %= mod;
  }
  cout << ans << endl;
*/
