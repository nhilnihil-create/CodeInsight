#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, sum = 0;
  cin >> n;
  vector<int> vt(n);
  for (int i = 0; i < n; ++i) {
    cin >> vt[i];
    sum += vt[i];
  }

  int m;
  cin >> m;
  vector<pair<int, int>> vp(m);
  for (auto &p : vp) {
    cin >> p.first >> p.second;
    p.first--;
  }

  for (auto &p : vp) {
    cout << sum - (vt[p.first] - p.second) << '\n';
  }
}