#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Returns a vector of cumulative sums.
// Let c_sums be the return value.
// - c_sums[k] is the sum of xs over [0, k).
// - c_sums[r] - c_sums[l] is the sum of xs over [l, r).
template<class T> vector<T> CumulativeSumVector(const vector<T>& xs) {
  int n = xs.size(); vector<T> c_sums(n + 1);
  for (int i = 0; i < n; i++) c_sums[i + 1] = c_sums[i] + xs[i];
  return c_sums;
}

vector<int> Encode(const string& s) {
  vector<int> xs(s.length());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      xs[i] = 1;
    }
  }
  return CumulativeSumVector(xs);
}

int Type(int a, int b) {
  a %= 3;
  b %= 3;
  vector<vector<int>> table = {{2, 1, 0}, {0, 2, 1}, {1, 0, 2}};
  return table[a][b];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s1, s2;
  cin >> s1 >> s2;
  auto cs1 = Encode(s1);
  auto cs2 = Encode(s2);

  int q_count;
  cin >> q_count;
  for (int q = 0; q < q_count; q++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--;
    l2--;
    
    int a1 = cs1[r1] - cs1[l1];
    int b1 = r1 - l1 - a1;
    int a2 = cs2[r2] - cs2[l2];
    int b2 = r2 - l2 - a2;
    if (Type(a1, b1) == Type(a2, b2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}