#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;


void solve(int W, int H, int N, vector<int> x, vector<int> y, vector<int> a) {
  int left(0), right(W), top(H), bottom(0);
  REP(i, N) {
    switch (a[i]) {
    case 1:
      left = max(left, x[i]);
      break;
    case 2:
      right = min(right, x[i]);
      break;
    case 3:
      bottom = max(bottom, y[i]);
      break;
    case 4:
      top = min(top, y[i]);
      break;
    }
  }
  cout << max(0, right - left) * max(0, top - bottom) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int W, H, N;
  cin >> W >> H >> N;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> a(N);
  REP(i, N)
    cin >> x[i] >> y[i] >> a[i];

  solve(W, H, N, move(x), move(y), move(a));

  return 0;
}
