#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int N,W; cin >> N >> W;
  vector<ll> w(N),v(N);
  rep(i,N) cin >> w[i] >> v[i];
  
  vector<vector<ll>> q(4);
  
  rep(i,N){
    q[w[i]-w[0]].push_back(v[i]);
  }
  
  rep(i,4){
    sort(q[i].begin(),q[i].end(),greater<ll>());
  }
  
  vector<vector<ll>>q_c(4);
  rep(i,4){
    q_c[i].push_back(0);
    rep(j,q[i].size()){
      ll tmp = q_c[i].back();
      q_c[i].push_back(tmp + q[i][j]);
    }
  }
  
  ll ans = 0;
  rep(i,q[0].size()+1){
    ll weight = 0, value = 0;
    rep(j,q[1].size()+1){
      rep(k,q[2].size()+1){
        rep(l,q[3].size()+1){
          weight = w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l;
          value = q_c[0][i]+q_c[1][j]+q_c[2][k]+q_c[3][l];
          if(weight <= W) chmax(ans,value);
        }
      }
    }
  }
/*  
  rep(i,4){
    for(auto x:q_c[i]){
      cout << x << " ";
    }
    cout << endl;
  }
*/
  cout << ans << endl;
  
  return 0;
}