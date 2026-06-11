#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

ll com[51][51];

int main(){
  com[0][0] = 1;
  for (int i = 1; i < 51; i++){
    for(int j = 0; j <= i; j++){
      com[i][j] += com[i-1][j];
      if(j>0) com[i][j] += com[i-1][j-1];
    }
  }
  
  int n,a,b; cin >> n >> a >> b;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(),v.end(),greater<ll>());
  
  ll sum = 0;
  rep(i,a) sum += v[i];
  double ave = (double)sum/a;
  printf("%.10f\n",ave);
  
  //一番小さい数の数。
  int cnt = 0;
  //場合の数（答え）
  ll ans = 0;
  rep(i,n){
    if(v[i]==v[a-1]) cnt++;
  }
  
  if(v[0]==v[a-1]){
    for(int i = a; i <= b; i++){
      ans += com[cnt][i];
    }
  }else{
    int cnt_inA = 0;
    rep(i,a) if(v[i] == v[a-1]) cnt_inA++;
    ans += com[cnt][cnt_inA];
  }
  
  // 計算例
  cout << ans << endl;
  return 0;
}