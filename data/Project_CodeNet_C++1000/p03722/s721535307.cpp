#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

const ll INF = 1LL << 60;

int main(){
  int n,m;
  cin >> n >> m;
  const int NMAX = 1000;
  const int MMAX = 2000;
  int a[MMAX], b[MMAX];
  ll c[MMAX];
  
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    c[i] = -c[i];
  }
  
  ll dist[NMAX];
  
  rep(i,n) dist[i] = INF;
  dist[0] = 0;
  
  rep(loop,n-1){
    rep(i,m){
      if(dist[a[i]-1] == INF) continue;
      if(dist[b[i]-1] > dist[a[i]-1]+c[i]){
        dist[b[i]-1] = dist[a[i]-1]+c[i];
      }
    }
  }
  
  ll ans = dist[n-1];
  bool negative[NMAX];
  rep(i,n) negative[i] = false;
  
  rep(loop,n){
    rep(i,m){
      if(dist[a[i]-1] == INF) continue;
      if(dist[b[i]-1] > dist[a[i]-1] + c[i]){
        dist[b[i]-1] = dist[a[i]-1] + c[i];
        negative[b[i]-1] = true;
      }
      if(negative[a[i]-1] == true){
        negative[b[i]-1] = true;
      }
    }
  }
  
  if(negative[n-1]) cout << "inf" << endl;
  else cout << -ans << endl;
  
  
  return 0;
}