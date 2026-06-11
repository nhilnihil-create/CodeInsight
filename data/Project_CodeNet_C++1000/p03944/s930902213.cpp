#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<int> a(n);
  rep(i, n) {
    int numx, numy, numa;
    cin >> numx >> numy >> numa;
    x.at(i) = numx;
    y.at(i) = numy;
    a.at(i) = numa;
  }
  vector<vector<int>> data(h, vector<int>(w, 1));
  rep(i, n) {
    if (a.at(i) == 1) {
      rep(j, x.at(i)) {
        rep(k, h) {
          data.at(k).at(j) = 0;
        }
      }
    }
    if (a.at(i) == 2) {
      for (int j = x.at(i); j < w; j++) {
        rep(k, h) {
          data.at(k).at(j) = 0;
        }
      }
    }
    if (a.at(i) == 3) {
      rep(j, y.at(i)) {
        rep(k, w) {
          data.at(j).at(k) = 0;
        }
      }
    }
    if (a.at(i) == 4) {
      for (int j = y.at(i); j < h; j++) {
        rep(k, w) {
          data.at(j).at(k) = 0;
        }
      }
    }
  }
  int count = 0;
  rep(i, h) {
    rep(j, w) {
      //cout << data.at(i).at(j);
      if (data.at(i).at(j) == 1) {
        count++;
      }
    //cout << endl;
    }
  }
  cout << count << endl;
}