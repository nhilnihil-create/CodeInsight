#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x){
  return x * x;
}

signed main (){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> C(H,vector<char>(W));
  rep(i,H)rep(j,W)cin >> C.at(i).at(j);  
rep(i,H){
  rep(k,2){
  rep(j,W){
  cout << C.at(i).at(j);
  if(j == W-1){cout << endl;}
  }
  }
}
  return 0;
}
