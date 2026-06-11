#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int x, y;
  cin >> x >> y;

  int grp[] = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
  if (grp[x - 1] == grp[y - 1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}