#include <bits/stdc++.h>
using namespace std;

long long n, k, c;
vector<long long> t;

int main() {
  cin >> n >> c >> k;
  t.resize(n);
  for (int i = 0; i < n; ++i) cin >> t[i];
  sort(t.begin(), t.end());
  long long res = 0;
  for (int i = 0; i < n;) {
    long long now = t[i] + k, cnt = 0;
    while (i < n && now >= t[i] && cnt < c) {
      ++i;
      ++cnt;
    }
    ++res;
  }
  cout << res << endl;
  return 0;
}
