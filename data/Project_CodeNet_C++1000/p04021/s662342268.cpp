#include <bits/stdc++.h>
using namespace std;

long long n;
vector<int> a, id;

int main() {
  cin >> n;
  a.resize(n);
  id.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    id[i] = i;
  }
  auto f = [](int l, int r) { return a[l] < a[r]; };
  sort(id.begin(), id.end(), f);
  int cnt = 0;
  for (int i = 0; i < n; i += 2)
    if ((i ^ id[i]) & 1) ++cnt;
  cout << cnt << endl;
  return 0;
}
