#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  vector<int> pri(3);
  rep(i, 3) cin >> pri.at(i);
  sort(pri.begin(), pri.end());
  cout << pri.at(0) + pri.at(1) << endl;
}
