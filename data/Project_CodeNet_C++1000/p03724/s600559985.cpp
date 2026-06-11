#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n + 1, 0);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    c[a]++;
    c[b]++;
  }
  bool ok = true;
  for(int i = 0; i <= n; i++) {
    if(c[i] % 2 != 0) {
      ok = false;
      break;
    }
  }
  if(ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}