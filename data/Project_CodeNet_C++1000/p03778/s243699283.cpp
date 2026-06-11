#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int W, a, b;
  cin >> W >> a >> b;

  cout << (abs(a - b) <= W ? 0 : abs(a - b) - W) << endl;
  return 0;
}
