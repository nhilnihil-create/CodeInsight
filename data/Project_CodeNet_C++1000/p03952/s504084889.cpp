#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> ans(2 * n - 1);
  for (int i = n - 1; i < n - 1 + 2 * n; ++i) {
    ans[i % (2 * n - 1)] = (i - (n - 1) + (x - 1)) % (2 * n - 1) + 1;
  }
  cout << "Yes" << endl;
  for (int i : ans) {
    cout << i << '\n';
  }
  return 0;
}
