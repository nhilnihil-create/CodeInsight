#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

const int MOD = 1000000007;

int main(){
  int n; cin >> n;
  vector<string> s(2);
  rep(i,2) cin >> s[i];
  
  ll ans = 1;
  bool vertical = false;
  rep(i,n){
    if(s[0][i]==s[1][i]){//ドミノが縦のケース
      if(i==0){
        ans *= 3;
      }else if(vertical){//前が縦だった場合
        ans *= 2;
      }else{
        ans *= 1;
      }
      vertical = true;
    }else{//ドミノが横のケース
      if(i==0){
        ans *= 6;
      }else if(vertical){
        ans *= 2;
      }else{
        ans *= 3;
      }
      vertical = false;
      i++;
    }
    ans %= MOD;
  }
  
  cout << ans << endl;
  return 0;
}