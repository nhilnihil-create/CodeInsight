#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), pos(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  vector<int> a(n + 1), b(n + 1);
  a[1] = 1, b[1] = 1e9;
  for (int i = 2; i <= n; ++i) {
    a[i] = a[i - 1] + 1;
    b[i] = b[i - 1] - 1;
    int k = pos[i] - pos[i - 1];
    if (k < 0) {
      b[i] += k;
    } else {
      a[i] += k;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << ' ';
  }
  cout << endl;
  return 0;
}