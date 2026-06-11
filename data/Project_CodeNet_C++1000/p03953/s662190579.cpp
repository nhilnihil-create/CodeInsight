#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

vector<int> PermutationComposite(const vector<int>& ps, const vector<int>& qs) {
  int n = ps.size();
  vector<int> rs(n);
  for (int i = 0; i < n; i++) {
    rs[i] = ps[qs[i]];
  }
  return rs;
}

vector<int> PermutationPower(const vector<int>& ps, int64 power) {
  if (power == 0) {
    int n = ps.size();
    vector<int> qs(n);
    for (int i = 0; i < n; i++) qs[i] = i;
    return qs;
  } else if (power == 1) {
    return ps;
  } else if (power % 2 == 0) {
    auto qs = PermutationPower(ps, power / 2);
    return PermutationComposite(qs, qs);
  } else {
    return PermutationComposite(PermutationPower(ps, power - 1), ps);
  }
}

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
  }
  s << "]";
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }
  vector<int64> ds(n - 1);
  for (int i = 0; i < n - 1; i++) {
    ds[i] = xs[i + 1] - xs[i];
  }

  vector<int> ps(n - 1);
  for (int i = 0; i < n - 1; i++) {
    ps[i] = i;
  }

  int m;
  int64 k;
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    a--;
    swap(ps[a - 1], ps[a]);
  }

  // cout << "ps: " << ps << endl;
  auto qs = PermutationPower(ps, k);
  // cout << "qs: " << ps << endl;

  vector<int64> es(n - 1);
  for (int i = 0; i < n - 1; i++) {
    es[i] = ds[qs[i]];
  }

  vector<int64> ys(n);
  ys[0] = xs[0];
  for (int i = 1; i < n; i++) {
    ys[i] = ys[i - 1] + es[i - 1];
  }

  for (int i = 0; i < n; i++) {
    cout << ys[i] << "\n";
  }
}
