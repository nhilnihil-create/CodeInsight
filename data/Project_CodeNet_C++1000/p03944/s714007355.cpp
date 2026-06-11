#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  //in
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<int> a(n);
  REP(i,n) cin >> x[i] >> y[i] >> a[i];
  
  //xl, xr, yl, yrの範囲を決めていく
  //4点の初期位置を決定
  int xl, xr, yl, yr;
  xl = 0;
  xr = w;
  yl = 0;
  yr = h;  
//REP で4点を更新max, min
  REP(i,n){
    if(a[i] == 1){
      xl = max(xl, x[i]);
    }
    if(a[i] == 2){
      xr = min(xr, x[i]);
    }
    if(a[i] == 3){
      yl = max(yl, y[i]);
    }
    if(a[i] == 4){
      yr = min(yr, y[i]);
    } 
  }

  //仮にr - l <= 0 ならば0

  if(xr - xl <= 0 || yr - yl <= 0){
    cout << 0 << endl;
    return 0;
  }

  //出力
  int ans = (xr - xl) * (yr - yl);
  cout << ans << endl;
  
  return 0;
}