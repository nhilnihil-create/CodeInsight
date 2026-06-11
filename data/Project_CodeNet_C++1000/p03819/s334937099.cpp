#include <bits/stdc++.h>
using namespace std;
using PP = pair<int, int>;

class BIT {
  const int n;
  vector<int> v;
public:
  BIT(int n) : n(n), v(n + 1) {}
  void add(int i, int d) {
    for (++i; i <= n; i += i & -i) {
      v[i] += d;
    }
  }
  int get(int i) const {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += v[i]; 
    }
    return sum;
  }
};

int n, m;
vector<PP> ps;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    ++r;
    ps.push_back(PP(l, r));
  }
  
  sort(ps.begin(), ps.end(), [](PP a, PP b) {
    return a.second - a.first < b.second - b.first;
  });
  
  BIT bit(m + 2);
  int i = 0;
  for (int j = 1; j <= m; ++j) {
    while (i < n && (ps[i].second - ps[i].first) < j) {
      bit.add(ps[i].first, 1);
      bit.add(ps[i].second, -1);
      ++i;
    }

    int ans = n - i;
    for (int k = 0; k <= m; k += j) {
      ans += bit.get(k + 1);
    }
    cout << ans << endl;
  }
}