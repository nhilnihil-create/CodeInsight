#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

signed main() {
  int h, w; cin >> h >> w;
  char c[h+1][w+1];
  for(int i=1; i<h+1; ++i) {
    for(int j=1; j<w+1; ++j) {
      cin >> c[i][j];
    }
  }
  h*=2;
  for(int i=1; i<h+1; ++i) {
    for(int j=1; j<w+1; ++j) {
      cout << c[(i+1)/2][j];
    }
    cout << endl;
  }

  return 0;
}
