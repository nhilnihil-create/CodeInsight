#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  string s;cin >> s;
  vector<vector<int>> lis(s.size(),vector<int>(26,0));
  for(int i = s.size()-1;i>=0;i--){
    if(i != s.size()-1) rep(j,26) lis[i][j] = lis[i+1][j];
    lis[i][s[i]-'a']++;
  }
  ll ans = 0;
  rep(i,s.size()-1){
    rep(j,26){
      if(j != (s[i]-'a')) ans+=lis[i+1][j];
    }
  }

  cout << ans+1 << endl;
}