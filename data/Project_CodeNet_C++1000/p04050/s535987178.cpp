#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a, odd;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;

    if (x & 1)
      odd.push_back(x);
    else
      a.push_back(x);
  }

  if ((n & 1) + odd.size() >= 3) {
    puts("Impossible");
    return 0;
  }

  for (int i = 0; i < odd.size(); ++i) {
    a.push_back(odd[i]);
    reverse(a.begin(), a.end());
  }

  if (n == 1) {
    cout << 1 << endl;
    cout << 1 << endl;
    cout << 1 << endl;

    return 0;
  }

  if (m == 1) {
    cout << a[0] << endl;
    cout << 2 << endl;
    cout << a[0] - 1 << endl;
    cout << 1 << endl;

    return 0;
  }

  for (int i = 0; i < m; ++i) {
    cout << a[i] << (i + 1 == m ? "\n" : " ");
  }

  vector<int> b;
  if (a[0] != 1) b.push_back(a[0] - 1);
  a[0] = 1;

  for (int i = 1; i < a.size() - 1; ++i) {
    b.push_back(a[i]);
  }

  b.push_back(2);
  if (a.back() != 1) b.push_back(a.back() - 1);

  cout << b.size() << endl;
  for (int i = 0; i < b.size(); ++i) {
    cout << b[i] << endl;
  }
}
