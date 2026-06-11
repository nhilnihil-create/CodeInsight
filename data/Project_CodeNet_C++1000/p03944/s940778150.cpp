#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n), y(n), a(n);
  rep(i, n) cin >> x[i] >> y[i] >> a[i];

  vector<vector<int>> white(w, vector<int>(h, 1));
  rep(i, n) rep(j, w) rep(k, h) {
    if (a[i] == 1 && j < x[i]) white[j][k] = 0;
    if (a[i] == 2 && j >= x[i]) white[j][k] = 0;
    if (a[i] == 3 && k < y[i]) white[j][k] = 0;
    if (a[i] == 4 && k >= y[i]) white[j][k] = 0;
  }

  int s = 0;
  rep(i, w) rep(j, h) s += white[i][j];
  cout << s << endl;
  return 0;
}