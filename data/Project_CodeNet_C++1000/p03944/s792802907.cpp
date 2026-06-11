#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<P> coor;
  vector<int> a;
  rep(i, n) {
    int x, y, z;
    cin >> x >> y;
    coor.emplace_back(x, y);
    cin >> z;
    a.push_back(z);
  }
  
  // 始点と終点の座標を狭めていく
  P start = make_pair(0, 0), end = make_pair(w, h);
  rep(i, n) {
    if (a[i] == 1) start.first = max(start.first, coor[i].first);
    else if (a[i] == 2) end.first = min(end.first, coor[i].first);
    else if (a[i] == 3) start.second = max(start.second, coor[i].second);
    else end.second = min(end.second, coor[i].second);
  }
  
  // 始点と終点の間の面積が答え
  int ww, wh;
  ww = end.first - start.first;
  wh = end.second - start.second;
  if (end.first <= start.first) ww = 0;  // 白い部分が残っていない
  if (end.second <= start.second) wh = 0;  // 同上
  
  cout << ww * wh << endl;
}