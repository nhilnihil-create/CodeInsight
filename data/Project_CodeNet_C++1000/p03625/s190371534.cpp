#include <bits/stdc++.h>

using namespace std;

struct cmp {
  bool operator()(const int &a, const int &b) const {
    return a > b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a;
  cin >> n;
  map<long long, int, cmp> hash;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    hash[a]++;
  }
  int done = 0;
  long long res = 1;
  for (auto &h: hash) {
    if (done > 1) break;
    if (h.second > 3) {
      if (done == 0) res = h.first * h.first;
      else res *= h.first;
      done = 2;
    } else if (h.second > 1) {
      done++;
      res *= h.first;
    }
  }
  cout << (done < 2 ? 0 : res) << endl;

  return 0;
}

