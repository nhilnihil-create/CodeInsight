#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vl = vector<ll>;  // long longの1次元の型に vl という別名をつける
using vvl = vector<vl>; // long longの2次元の型に vvl という別名をつける
int MOD = 1000000007; //10^9 + 7

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 無限大の値
const ll INF = 1LL << 60;

void cycle(bool h, bool v, int dx, int dy){
  if(h) rep(i, dx) cout << 'R';
  else rep(i, dx) cout << 'L';
  if(v) rep(i,dy) cout << 'U';
  else rep(i, dy) cout << 'D';
}

int main(void){
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int dx = tx - sx, dy = ty - sy;
  cycle(dx>0, dy>0, abs(dx), abs(dy));
  cycle(-dx>0, -dy>0, abs(dx), abs(dy));

  if(dy>0){
    if(dx>0){
      cout << 'D';
      cycle(dx>0, dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'L' << 'U';
      cycle(-dx>0, -dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'R';
    }
    else{
      cout << 'D';
      cycle(dx>0, dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'R' << 'U';
      cycle(-dx>0, -dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'L';
    }
  }
  else{
    if(dx>0){
      cout << 'U';
      cycle(dx>0, dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'L' << 'D';
      cycle(-dx>0, -dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'R';
    }
    else{
      cout << 'U';
      cycle(dx>0, dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'R' << 'D';
      cycle(-dx>0, -dy>0, abs(dx)+1, abs(dy)+1);
      cout << 'L';
    } 
  }
  return 0;
}