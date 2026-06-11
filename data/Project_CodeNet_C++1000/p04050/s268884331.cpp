#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  deque<int> a(m), idx;

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    if (a[i] & 1) idx.push_back(i);
  }

  if ((n & 1) + idx.size() >= 3) {
    puts("Impossible");
    return 0;
  }

  idx.resize(2);
  swap(a[idx[1]], a[0]);
  swap(a[idx[0]], a.back());

  for (int i = 0; i < m; ++i) cout << a[i] << endl;

  if (m == 1) a.push_back(0);
  a[0]--;
  a.back()++;
  if (a[0] == 0) a.pop_front();

  cout << a.size() << endl;
  for (int i = 0; i < a.size(); ++i) cout << a[i] << endl;
}
