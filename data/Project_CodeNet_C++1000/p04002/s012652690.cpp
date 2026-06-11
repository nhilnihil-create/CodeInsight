#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int h, w, n;
set<pair<int, int>> is;
set<pair<int, int>> calc;

int get(int i, int j) {
  int sol = 0;
  for (int a = i; a <= i + 2; a++) {
    for (int b = j; b <= j + 2; b++) {
      sol += is.count({a, b});
    }
  }
  return sol;
}

int f[10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> w >> n;
  h -= 2;
  w -= 2;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    is.insert({x, y});
  }
  for (auto &it : is) {
    int x = it.first;
    int y = it.second;
    for (int a = x - 2; a <= x; a++) {
      for (int b = y - 2; b <= y; b++) {
        calc.insert({a, b});
      }
    }
  }
  for (auto &it : calc) {
    int x = it.first;
    int y = it.second;
    if (1 <= x && 1 <= y && x <= h && y <= w) {
      f[get(x, y)]++;
    }
  }
  ll f0 = (ll) h * w - (f[1] + f[2] + f[3] + f[4] + f[5] + f[6] + f[7] + f[8] + f[9]);
  cout << f0 << "\n";
  for (int i = 1; i <= 9; i++) {
    cout << f[i] << "\n";
  }
}
