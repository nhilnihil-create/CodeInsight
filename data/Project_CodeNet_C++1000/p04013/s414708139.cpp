#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}



int main() {
  int N,A;
  cin >> N >> A;
  vector<int> X(N);
  rep(i,N) cin >> X[i];
  vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(N+1,vector<ll>(2501,0)));
  dp[0][0][0]=1;
  rep2(i,1,N+1){//ターン
    int x = X[i-1];
    rep(j,N+1){//枚数
      rep(k,2501){
        dp[i][j][k] = dp[i-1][j][k];
        if (j>0&&k-x>=0) dp[i][j][k]+=dp[i-1][j-1][k-x];
      }
    }
  }
  ll res=0;
  rep2(i,1,N+1) res += dp[N][i][A*i];
  cout << res << endl;
}