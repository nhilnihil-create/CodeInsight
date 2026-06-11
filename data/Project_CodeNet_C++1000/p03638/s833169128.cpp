#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<int> v;
  rep(i, N) rep(j, a[i]) v.push_back(i + 1);

  rep(i, H) {
    rep(j, W) {
      int k = j;
      if (i % 2 != 0)
        k = W - 1 - j;
      if (j != 0)
        cout << " ";
      cout << v[i * W + k];
    }
    cout << endl;
  }
}