#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;

  vector<int> v(101);
  v[1] = 0;
  for (int i = 2; i <= 100; ++i) {
    int j = i;
    int count = 0;
    while (j % 2 == 0) {
      count++;
      j /= 2;
    }
    v[i] = count;
  }

  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (v[ans] < v[i]) {
      ans = i;
    }
  }

  cout << ans << endl;
  
  return 0;
}