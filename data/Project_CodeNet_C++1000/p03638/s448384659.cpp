#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return a;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


int main() {
  int H,W; cin >>H >>W;
  int N; cin >>N;
  vector<int> A(N); rep(i, N) cin >>A.at(i);
  vector<int> color(H*W);
  int tmpi = 0;
  for (int i=0; i<H*W; i++){
    if (A.at(tmpi)==0) tmpi++;
    color.at(i) = tmpi+1;
    A.at(tmpi)--;
  }
  vector<vector<int>> table(H, vector<int>(W, 0));

  int colori = 0;
  for (int i=0; i<H; i++){
    if (i%2==0){
      for (int j=0; j<W; j++){
        table.at(i).at(j) = color.at(colori);
        colori++;
      }
    }
    if (i%2==1){
      for (int j=W-1; j>=0; j--){
        table.at(i).at(j) = color.at(colori);
        colori++;
      }
    }
  }

  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      cout <<table.at(i).at(j);
      if (j == W-1) cout <<endl;
      else cout <<" ";
    }
  }

}