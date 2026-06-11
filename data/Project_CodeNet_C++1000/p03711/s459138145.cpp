#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  vector<int> vec = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  int x, y;
  cin >> x >> y;
  if(vec[x] == vec[y]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
