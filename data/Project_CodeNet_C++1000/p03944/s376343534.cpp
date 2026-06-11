#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<int> a(n);
  rep(i, n) cin >> x[i] >> y[i] >> a[i];

  int lx = 0, ly = 0;
  int ux = w, uy = h;
  rep(i, n){
    if (a[i] == 1){
      if (lx < x[i]) lx = x[i];
    } else if (a[i] == 2){
      if (ux > x[i]) ux = x[i];
    } else if (a[i] == 3){
      if (ly < y[i]) ly = y[i];
    } else if (a[i] == 4){
      if (uy > y[i]) uy = y[i];
    }
  }

  int ansx = ux - lx;
  int ansy = uy - ly;
  if ((ansx > 0) && (ansy > 0)){
    cout << ansx * ansy << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}