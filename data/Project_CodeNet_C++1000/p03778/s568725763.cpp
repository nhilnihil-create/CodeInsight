#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int w, a, b;
  cin >> w >> a >> b;

  // 数直線上で左をaとしてしまう
  // どちらを移動させても距離は同じため
  // 実際に動かして表示するならよくない
  if (a > b) swap(a, b);

  // すでに重なっているか
  if (a + w >= b) {
    cout << 0 << endl;
  } else {
    // 重なっていないなら計算
    cout << b - (a + w) << endl;
  }
  
  return 0;
}