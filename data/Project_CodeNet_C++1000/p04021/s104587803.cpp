#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N], b[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1);
  set <int> s;
  for (int i = 1; i <= n; i += 2) {
    s.emplace(a[i]);
  }
  for (int i = 1; i <= n; i += 2) {
    s.erase(b[i]);
  }
  cout << s.size() << '\n';
  return 0;
}

