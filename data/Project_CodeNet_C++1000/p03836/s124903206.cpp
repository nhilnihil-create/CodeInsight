#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

//  ABC051 C - Back and Forth
// 2020.06.14

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  string ans;
  // (1)
  int sx1 = sx, sy1 = sy+1, tx1 = tx-1, ty1 = ty;
  ans += "U";
  REP(i, ty1-sy1){
    ans += "U";
  }
  REP(i, tx1-sx1){
    ans += "R";
  }
  ans += "R";

  // (2)
  int sx2 = sx+1, sy2 = sy, tx2 = tx, ty2 = ty-1;
  ans += "D";
  REP(i, ty2-sy2){
    ans += "D";
  }
  REP(i, tx2-sx2){
    ans += "L";
  }
  ans += "L";

  // (3)
  int sx3 = sx, sy3 = sy-1, tx3 = tx+1, ty3 = ty;
  ans += "D";
  REP(i, tx3-sx3){
    ans += "R";
  }
  REP(i, ty3-sy3){
    ans += "U";
  }
  ans += "L";

  // (4)
  int sx4 = sx-1, sy4 = sy, tx4 = tx, ty4 = ty+1;
  ans += "U";
  REP(i, tx4-sx4){
    ans += "L";
  }
  REP(i, ty4-sy4){
    ans += "D";
  }
  ans += "R";

  cout << ans << endl;
}