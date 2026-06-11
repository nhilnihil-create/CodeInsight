#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  
  vector<int> x(N);
  vector<int> y(N);
  vector<int> a(N);
  
  for (int i = 0; i < N; i++) {
	cin >> x.at(i) >> y.at(i) >> a.at(i);
  }

  int xlow, xup, ylow, yup;
  xlow = 0;
  xup = W;
  ylow = 0;
  yup = H;
  
  for (int i = 0; i < N; i++) {
    if ( a.at(i) == 1 ) {
      if ( x.at(i) > xlow ) {
        xlow = x.at(i);  
      }
    }
    else if ( a.at(i) == 2 ) {
      if ( x.at(i) < xup ) {
        xup = x.at(i);  
      }
    }
    else if ( a.at(i) == 3 ) {
      if ( y.at(i) > ylow ) {
        ylow = y.at(i);  
      }
    }
    else {
      if ( y.at(i) < yup ) {
        yup = y.at(i);  
      }
    }
  }  
  
  if ( xup >= xlow && yup >= ylow ) {
    cout << max ((xup-xlow)*(yup-ylow), 0) << endl;
  }
  else {
    cout << 0 << endl;
  }
}