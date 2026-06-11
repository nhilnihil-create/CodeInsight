#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> c(h, vector<char> (w));
  rep(i,h) {
    rep(j,w) cin >> c[i][j];
  }
  
  rep(i,h) {
    rep(j,w) cout << c[i][j];
    cout << endl;
    rep(j,w) cout << c[i][j];
    cout << endl;
  }
}