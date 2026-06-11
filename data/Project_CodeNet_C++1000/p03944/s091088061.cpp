#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) <= (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 998244353;


int main(){
  int W, H, N;
  cin >> W >> H >> N;
  int lx = 0, rx = W, bh = 0, th = H;
  REP(i, N){
    int x, y, a;
    cin >> x >> y >> a;
    if(a == 1){
      lx = max(lx, x);
    }
    else if(a==2){
      rx = min(rx, x);
    }
    else if(a==3){
      bh = max(bh, y);
    }
    else if(a==4){
      th = min(th, y);
    }
  }
  cout << max(0, rx-lx) * max(0, th-bh) << endl;
  return 0;
}
