#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  vector<vector<int>> ch(26);
  rep(i,26) ch[i].push_back(-1);
  int l = s.size();
  rep(i,l){
    ch[s[i]-'a'].push_back(i);
  }
  rep(i,26){
    ch[i].push_back(l);
  }
  int ans=1<<30;
  rep(i,26){
    int M = 0;
    rep(j,(int)ch[i].size()-1){
      chmax(M,ch[i][j+1]-ch[i][j]);
    }
    chmin(ans,M);
  }
  cout<<ans-1<<endl;
}