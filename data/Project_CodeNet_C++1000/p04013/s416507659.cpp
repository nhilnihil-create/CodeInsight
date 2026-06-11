#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

ll dp[55][55][2505];
int n,a;
int x[55];

int main(){
  cin >> n >> a;
  rep(i,n) cin >> x[i];
  
  dp[0][0][0] = 1;
  rep(i,n){
    for(int j = 0; j <= i; j++){
      rep(k,2505){
        if(k+x[i] < 2505){
          //i枚目を選んだ場合
          dp[i+1][j+1][k+x[i]] += dp[i][j][k];
          //i枚目を選ばない場合
          dp[i+1][j][k] += dp[i][j][k];
        }
      }
    }
  }
  
  ll ans = 0;
  
  for(int j = 1; j <= n; j++){
    ans += dp[n][j][a*j];
  }
  
  cout << ans << endl;
  
  return 0;
}