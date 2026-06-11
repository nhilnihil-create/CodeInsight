#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int W, H, N; cin >> W >> H >> N;
  int X1 = 0, X2 = W, Y1 = 0, Y2 = H;
  REP(i, N){
    int x, y, a; cin >> x >> y >> a;
    if(a == 1){
      X1 = max(X1, x);
    }else if(a == 2){
      X2 = min(X2, x);
    }else if(a == 3){
      Y1 = max(Y1, y);
    }else if(a == 4){
      Y2 = min(Y2, y);
    }
  }
  int ans = 0;
  if(X2-X1 >= 0 && Y2-Y1 >= 0){
    ans = (X2-X1)*(Y2-Y1);
  }
  cout << ans << endl;
}