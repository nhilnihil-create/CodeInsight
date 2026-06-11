#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const int M = 1000005;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> c(h, vector<char>(w));
  rep(i, h){
    rep(j, w){
      cin >> c[i][j];
    }
  }
  rep(i, h){
    int k = 2;
    while(k--){
      rep(j, w){
        cout << c[i][j];
      }
      cout << endl;
    }
  }
}