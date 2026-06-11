#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

const int INF = 1 << 30;

int n,Ma,Mb;
int dp[45][405][405];
int a[45],b[45],c[45];

int main(){
  cin >> n >> Ma >> Mb;
  fill(dp[0][0],dp[45][0],INF);
  rep(i,n) cin >> a[i] >> b[i] >> c[i];
  
  dp[0][0][0] = 0;
/*
  rep(i,10){
    rep(j,10){
      cout << dp[0][i][j];
    }
  }
*/
  for(int i = 0;i < n;i++){
    rep(j,405){
      rep(k,405){
        if(dp[i][j][k] != INF){
          //i個目を選ぶ
          chmin(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
          //i個目を選ばない
          chmin(dp[i+1][j][k],dp[i][j][k]);
        }
      }
    }
  }
  
  int ans = INF;
  
  for(int i = 1; i < 405;i++){
    for(int j = 1; j < 405; j++){
      if(Ma*j==Mb*i) chmin(ans, dp[n][i][j]);
    }
  }
  
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
    
  return 0;
}