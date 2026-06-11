#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> m;
  vector<int> v;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    m[a]++;
    if (m[a] % 2 == 0) v.push_back(a);
  }
  if (v.size() < 2) {
    cout << 0 << endl;
    return 0;
  }
  sort(v.rbegin(), v.rend());
  long long ans = (long long)v[0] * v[1];
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
