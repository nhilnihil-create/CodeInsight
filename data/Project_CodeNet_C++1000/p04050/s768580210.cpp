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

  for (int i = 0; i < m; ++i) {
    cout << a[i] << (i + 1 == m ? "\n" : " ");
  }

  if (m == 1) a.push_back(0);

  a[0]--;
  a.back()++;

  cout << (a.size() - (a[0] == 0)) << endl;
  for (int i = (a[0] ? 0 : 1); i < a.size(); ++i) {
    cout << a[i] << endl;
  }
}
